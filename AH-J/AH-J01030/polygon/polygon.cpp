#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,k,sum,maxn;
int a[500005];
void dfs(int step,int cnt,int maxn)
{
	if(step==n+1)
	{
		if(maxn*2<cnt)
		{
			sum++;
		}
		return;
	}
	dfs(step+1,cnt+a[step],max(maxn,a[step]));
	dfs(step+1,cnt,maxn);
	return;
}
int C(int x,int y)
{
	y=min(y,x-y);
	__int128 z=1,f=1;
	for(int i=x;i>x-y;i--)
	{
		z*=i;
	}
	for(int i=1;i<=y;i++)
	{
		f*=i;
	}
	return z/f;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn<=1)
	{
		for(int i=3;i<=n;i++)
		{
			sum=(sum+C(n,i))%mod;
		}
	}
	else
	{
		dfs(1,0,0);
	}
	cout<<sum%mod<<"\n";
	return 0;
}
/*
*/
