#include <bits/stdc++.h>
using namespace std;
long long n,a[5010],ans,mod=998244353;
bool v;
void dfs(int u,long long sum,long long maxn,long long cnt)
{
	if(u>n)
	{
		if(cnt>=3&&sum>2*maxn)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(u+1,sum,maxn,cnt);
	int maxn2=max(a[u],maxn);
	dfs(u+1,sum+a[u],maxn2,cnt+1);
}
void solve1()
{
	dfs(1,0,0,0);
	cout<<ans;
}
long long cl(int p,int m)
{
	if(p>m/2)
	{
		p=m-p;
	}
	long long ab=1,dwm=1;
	for(int i=n;i>=n-p+1;i--)
	{
		ab*=i;
	}
	for(int i=p;i>=1;p--)
	{
		dwm*=p;
	}
	return (ab/p)%mod;
}
void solve2()
{
	for(int i=3;i<=n;i++)
	{
		ans+=cl(i,n);
		ans%=mod;
	}
	cout<<ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			v=1;
		}
	}
	if(n<=20)
	{
		solve1();
	}else if(v==0)
	{
		solve2();
	}
	return 0;
}
