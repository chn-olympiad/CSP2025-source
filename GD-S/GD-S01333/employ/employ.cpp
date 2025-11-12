#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll num[501],c[501],a[501];
bool vis[501];
string s;
ll n,m,ans=0;
void dfs(ll id)
{
	ll sum=0;
	if (id==n+1)
	{
		for (ll i=1;i<=n;i++)
		{
			if (sum>=a[i]||num[i]==0)
			{
				sum++;
			}
		}
		if (n-sum>=m)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	for (ll i=1;i<=n;i++)
	{
		if (vis[i]==1)
		{
			continue;
		}
		vis[i]=1;
		a[id]=c[i];
		dfs(id+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll l;
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for (ll i=0;i<n;i++)
	{
		num[i+1]=s[i]-'0';
	}
	for (ll i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	memset(vis,0,sizeof(vis));
	dfs(1);
	printf("%lld",ans%mod);
	return 0;
}
