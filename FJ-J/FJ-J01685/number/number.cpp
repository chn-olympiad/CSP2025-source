#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(int(s[i])>=int('0')&&int(s[i])<=int('9'))
		{
			a[++cnt]=0+(int(s[i])-int('0'));
		}
	}
	sort(a+1,a+cnt+1);
	if(a[cnt]==0)
	{
		printf("0");
	}
	else
	{
		for(int i=cnt;i;i--)
		{
			printf("%d",a[i]);
		}
	}
	return 0;
}
