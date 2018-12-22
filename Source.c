#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

struct student
{
	char N_S_S[BUFSIZ];
	int cost;
	char brand[BUFSIZ];
	int number;
};
//char *strcpy(char *destination, const char*source);
void recInFile(struct student *car, int i);
void read(struct student *car, int i);
void min_max(struct student *car, int i);
void readFile(struct student *car, int i);
void read(struct student *car, int i)
{
	for (int j = 0; j < i; j++)
	{
		printf("Введiть ПІП\n");
		scanf("%s", &car[j].N_S_S);
		printf("Введiть вартість\n");
		scanf("%d", &car[j].cost);
		printf("Введiть марку\n");
		scanf("%s", &car[j].brand);
		printf("Введiть номер\n");
		scanf("%d", &car[j].number);
		puts("");
	}
}
void recInFile(struct student *car, int i)
{
	
	FILE *fp;
	if ((fp = fopen("struct.txt", "wb")) == NULL)
	{
		puts("ERROR!");
		exit(1);
	}
	
	for (int j = 0; j < i; j++)
	{
		fwrite(car++, sizeof(car ), 1, fp);
	}
	fclose(fp);
	system("cls");
}
void min_max(struct student *car, int i){
	int tmp,tmp3, N=5;
	char tmp1[512], tmp2[512];
	for (int j = 0; j < N; j++){
		for (int i = 1; i < N-1; i++){
			if (car[i].cost>car[i+1].cost){
				tmp = car[i].cost;
				car[i].cost = car[i+1].cost;
				car[i+1].cost = tmp;

				strcpy(tmp1, car[i].N_S_S);
				strcpy(car[i].N_S_S, car[i+1].N_S_S);
				strcpy(car[i+1].N_S_S, tmp1);

				strcpy(tmp2, car[i].brand);
				strcpy(car[i].brand, car[i+1].brand);
				strcpy(car[i+1].brand, tmp2);

				tmp3 = car[i].number;
				car[i].number = car[i+1].number;
				car[i+1].number = tmp3;
			}
		}
	}
}
void readFile(struct student *car, int i)
{
	
	FILE *fp;
	if ((fp = fopen("struct.txt", "rb")) == NULL)
	{
		puts("ERROR!");
		exit(1);
	}
		

	for (int j = 0; j < i; j++){
		fread(car+j, sizeof(*car), 1, fp);
		
	}
	fclose(fp);
	for (int n = 0; n < 5; n++){
		printf("PIB of automobile = %s\n", car[n].N_S_S);
		printf("Value = %d\n", car[n].cost);
		printf("Brand = %s\n", car[n].brand);
		printf("Number = %d\n", car[n].number);
	}
}



int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ukr");
	struct student * car;
	car = (struct student *)malloc(5 * sizeof(struct student));
	read(car , 5); // функція ініціалізації масиву
	min_max(car, 5);
	recInFile(car, 5);
	readFile(car, 5);
	getchar();
	return 0;
}

