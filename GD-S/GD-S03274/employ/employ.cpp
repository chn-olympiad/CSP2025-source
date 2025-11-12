#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e4+5;
char a[N];
int wa[N],vis[N],c[N],st[N];
int ans,n,m,sum,cnt;
void dfs(int dep)
{
	if(dep==n)
	{
		sum=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0||sum>=wa[st[i]])
				sum++;
		}
		if(n-sum>=m)
			ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		st[dep+1]=i;
		dfs(dep+1);
		vis[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i],c[i]=a[i]-'0';
		cnt+=c[i];
	}
	for(int i=1;i<=n;i++)
		cin>>wa[i];
	if(n<=10)
	{
		for(int i=1;i<=n;i++)
		{
			vis[i]=1;
			st[1]=i;
			dfs(1);
			vis[i]=0;
		}
		cout<<ans;
		return 0;
	}
	if(cnt==n)
	{
		int ans=1;
		for(int i=2;i<=n;i++)
			ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	if(n==m)
	{
		sort(wa+1,wa+n+1);
		sum=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0||sum>=wa[st[i]])
				sum++;
		}
		if(n-sum>=m)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	return 0;
}
/*
3 2
101
1 1 2
*/
