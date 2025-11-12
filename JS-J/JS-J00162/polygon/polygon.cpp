#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Mod 998244353
int sum[5005];
int ls;
int n;
ll ni(ll d,int h=Mod-1)
{
	if(d==1)return 1;
	ll ans=1;
	while(h)
	{
		if(h&1)ans*=d,ans%=Mod;
		d*=d,d%=Mod;
		h>>=1;
	}
	return ans;
}
ll C(ll x,ll y)
{
	if(x==y)return 1;
	ll ans=1;
	for(int i=1;i<=y;i++)ans*=i,ans%=Mod;
	for(int i=1;i<=x-y;i++)ans*=i,ans%=Mod;
	ans=ni(ans);
	for(int i=1;i<=x;i++)ans*=i,ans%=Mod;
	return ans;
}
ll ans;
int shangx=0;
void dfs(int d=1,int num=0,int maxn=0,int kinds=1)
{
	if(d>shangx)
	{
		if(num>maxn*2)ans+=kinds,ans%=Mod;
	}
	else
	{
		dfs(d+1,num,maxn,kinds);
		if(!sum[d])return;
		for(int i=1;i<=sum[d];i++)
		{
			dfs(d+1,num+i*d,d,kinds*C(sum[d],i));
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ls;
		shangx=max(shangx,ls);
		sum[ls]++;
	}
	if(shangx==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=C(n,i);
			ans%=Mod;
		}
		cout<<ans;
		return 0;
	}
	dfs();
	cout<<ans;
	return 0;
}
