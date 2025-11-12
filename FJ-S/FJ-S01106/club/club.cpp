#include<bits/stdc++.h>
using namespace std;
using LL=long long;
long long read()
{
	char b=getchar();
	long long a=0;
	for(;'0'<=b&&b<='9';)
a=a*10+b-'0',b=getchar();
	return a;
}
long long t,n,a[101000][4],l[4],ans;
void dfs(LL x,LL y)
{
	if(x==n)
	{
		ans=max(ans,y);
		return;
	}
	for(LL j=1;j<=3;j++)
	{
		if(l[j]<n/2)
		{
			l[j]++;
			dfs(x+1,y+a[x+1][j]);
			l[j]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	for(long long i=1;i<=t;i++)
	{
		ans=0;
		n=read();
		for(LL j=1;j<=n;j++)
		{
			for(LL k=1;k<=3;k++)
				a[j][k]=read();
		}
		dfs(0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
