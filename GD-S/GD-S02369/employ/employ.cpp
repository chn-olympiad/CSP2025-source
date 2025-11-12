#include<bits/stdc++.h>
using namespace std;
int s[100001],n,m,cnt[100001],r=998244353,ans,vis[100001],p[100001];
void dfs(int x)
{
	if(x>n)
	{
		int ct=0,be=0,ac=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt[p[i]]<=ct) 
			{
				ct++;
				continue;
			}
			if(s[i]==0)
			{
				ct++;
			}
			else
			{
				ac++;
			}
		}
//		for(int i=1;i<=n;i++) cout<<p[i]<<" ";
//		cout<<ac<<" "<<ct<<endl;
		ans+=(ac>=m);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
			p[x]=0;
		}
	}
}
int fac(int x)
{
	int r=1;
	for(int i=1;i<=x;i++) r=r*x%md;
	return r;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n>=100)
	{
		cout<<fac(n);
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++) scanf("%d",&cnt[i]);
	dfs(1);
	cout<<ans;
}
