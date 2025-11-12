/*
40-48 pts
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e4;
const int mod=998244353;
int n;
int a[MAXN];
int b[MAXN];
int ans;
inline bool check(int num)
{
	int sum=0;
	for(int i=1;i<=num;++i)	sum+=b[i];
	if(sum>(b[num]*2))
		return true;
	else
		return false;
}
inline void dfs(int x,int cnt)
{
	if(x==n+1)
	{
		if(check(cnt))
			ans++;
		if(ans>=mod) ans-=mod;
		return ;
	}
	for(int i=1;i<=2;++i)
	{
		if(i==1)
		{
			dfs(x+1,cnt);
		}
		else
		{
			b[cnt+1]=a[x];
			dfs(x+1,cnt+1);
			b[cnt+1]=0;
		}
	}
	return ;
}
int ans1,ANS;
inline void dfs1(int x,int cnt,int w)
{
	if(x==n+1) return ;
	if(cnt==w)
	{
		ans1++;
		if(ans1>=mod) ans1-=mod;
		return;
	}
	if(x+w+cnt==n+1)
	{
		ans1++;
		if(ans1>=mod) ans1-=mod;
		return ;
	}
	for(int i=1;i<=2;++i)
	{
		if(i==1)
		{
			dfs(x+1,cnt);
		}
		else
		{
			dfs(x+1,cnt+1);
		}
	}
	return ;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n<=25)
	{	
		stable_sort(a+1,a+n+1);
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=3;i<=n;++i)
			dfs1(1,0,i);
		cout<<ans1;
		return 0;
	}
}