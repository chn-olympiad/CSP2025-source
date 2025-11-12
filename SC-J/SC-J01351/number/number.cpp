#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10];
char s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	do{
		s=getchar();
		if(s>='0'&&s<='9')
		{
			a[int(s-'0')]++;
		}
	}while(s!='\n');
	for(int i=9;i>=0;i--)
	{
		while(a[i]--)
			printf("%d",i);
	}
	return 0;
 } 