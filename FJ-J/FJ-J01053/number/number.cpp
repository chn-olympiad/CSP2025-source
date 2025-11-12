#include<bits/stdc++.h>
using namespace std;
#define ll long long
char c[1000005];
int cnt[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c+1);
	int n=strlen(c+1);
	for(int i=1;i<=n;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			cnt[c[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			printf("%d",i); 
		}
	}
	return 0;
}

