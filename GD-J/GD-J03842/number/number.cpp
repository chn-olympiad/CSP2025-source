#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int sum[1100];
char s[1100000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			sum[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(sum[i]--)
		{
			printf("%d",i);
		}
	}
	printf("\n");
}

