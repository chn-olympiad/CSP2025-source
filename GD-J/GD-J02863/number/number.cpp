#include<bits/stdc++.h>
#define int long long
using namespace std;
char s[1145141];
int a[114514],n;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			printf("%lld",i);
		}
	}
	return 0;
}
