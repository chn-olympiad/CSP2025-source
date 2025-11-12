#include<bits/stdc++.h>
using namespace std;
char s[2000000];
int num[2000000];
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
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=num[i];j++)
		{
			printf("%d",i);
		}
	}
	return 0;
}
