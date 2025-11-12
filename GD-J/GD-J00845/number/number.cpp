#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;


char chch;
unsigned int arrlen = 0;
int arr1[1000000];


inline bool isnum(char cha1)
{
	return ('0' <= cha1) && (cha1 <= '9'); 
}


bool comp(const int& a,const int& b)
{
	return a > b;
}


int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while (scanf("%c",&chch) != EOF)
	{
		if (isnum(chch))
		{
			arr1[arrlen++] = chch - '0';
		}
	}
	sort(arr1,arr1+arrlen,comp);
	for (int i = 0;i < arrlen;i++)
	{
		printf("%d",arr1[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

// 123
