#include<bits/stdc++.h>
using namespace std;
int a[10];
char s[1000005];
int main ()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	for(int i=0;i<strlen(s);i++)if('0'<=s[i] and s[i]<='9')a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
	{
		while(a[i]!=0)
		{
			printf("%d",i);
			a[i]--;
		}
	}
	return 0;
}

