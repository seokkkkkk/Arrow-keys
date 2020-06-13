#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32

int key;
int com;
int user;
int arrow[51];
float success = 0;
float fail = 0;
clock_t time1, time2;
double tottime;
int on = 1;
int off;
int score=0;

int randarrow()
{
	srand(time(NULL));
	for (int i = 0; i < 50; i++)
	{
		arrow[i] = rand() % 5 + 1;
	}
	return 0;
}

int key1()
{
	key = _getch();
	if (key == 224)
		key = _getch();
	return 0;
}

int output(int start, int end)
{
	for (int i = start; i < end; i++)
	{
		if (arrow[i] == 1)
		{
			printf("↑");
		}
		else if (arrow[i] == 2)
		{
			printf("↓");
		}
		else if (arrow[i] == 3)
		{
			printf("→");
		}
		else if (arrow[i] == 4)
		{
			printf("←");
		}
		else if (arrow[i] == 5)
		{
			printf("◎");
		}
	}
	return 0;
}
int game(int start, int end)
{
	for (int i = start; i < end; i++)
	{
		if (arrow[i] == 1)
		{
			key1();
			if (key == UP)
			{
				success++;
				printf("○");
			}
			else
			{
				fail++;
				printf("△");
			}
		}
		else if (arrow[i] == 2)
		{
			key1();
			if (key == DOWN)
			{
				success++;
				printf("○");
			}
			else
			{
				fail++;
				printf("△");
			}
		}
		else if (arrow[i] == 3)
		{
			key1();
			if (key == RIGHT)
			{
				success++;
				printf("○");
			}
			else
			{
				fail++;
				printf("△");
			}
		}
		else if (arrow[i] == 4)
		{
			key1();
			if (key == LEFT)
			{
				success++;
				printf("○");
			}
			else
			{
				fail++;
				printf("△");
			}
		}
		else if (arrow[i] == 5)
		{
			key1();
			if (key == SPACE)
			{
				success++;
				printf("○");
			}
			else
			{
				fail++;
				printf("△");
			}
		}
	}
	return 0;
}
int result()
{
	tottime = time2 - time1;
	printf("%0.2f초\n", tottime / 1000);
	printf("정확도 = %0.2f%%\n", (success / (success + fail)) * 100);
	for (int i = 0; i < 100; i++)
	{
		if ((success / (success + fail)) * 100 > i)
		{
			score = score + 1;
		}
		if (tottime/1000 < i)
		{
			score = score + 1;
		}
	}
	if (score < 0)
	{
		score = 0;
	}
	printf("점수: %d\n", score);
	return 0;
}

int main(void)
{
	while (on == 1)
	{
		printf("게임을 실행하려면 1을 입력하세요.");
		scanf("%d", &off);
		if (off == 1)
		{
			on = 0;
		}
		else
		{
			on = 1;
		}
	}
	randarrow();
	time1 = clock();
	printf("1단계\n");
	output(0, 5);
	printf("\n");
	game(0, 5);
	printf("\n");
	printf("2단계\n");
	output(5, 15);
	printf("\n");
	game(5, 15);
	printf("\n");
	printf("3단계\n");
	output(15, 30);
	printf("\n");
	game(15, 30);
	printf("\n");
	time2 = clock();
	result();
	return 0;
}
