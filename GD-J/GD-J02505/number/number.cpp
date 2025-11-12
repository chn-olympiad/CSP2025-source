#include<cstdio>
char s;
int a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&s)!=EOF)
	{
		if('0'<=s&&s<='9')
		{
			a[s-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<a[i];j++)
		{
			printf("%d",i);
		}
	}
	return 0;
}
