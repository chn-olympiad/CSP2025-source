#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll a[5001],shape[5001];
ll n,ans=0;
void dfs(ll id,ll cnt)
{
	ll sum=0,maxnum=0;
	if (id==n+1)
	{
		if (cnt<3)
		{
			return;
		}
		for (ll i=1;i<=cnt;i++)
		{
			sum+=shape[i];
			maxnum=max(maxnum,shape[i]);
		}
		if (sum>maxnum*2)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	shape[cnt+1]=a[id];
	dfs(id+1,cnt+1);
	dfs(id+1,cnt);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll maxx=0,total=1,x=1,y;
	scanf("%lld",&n);
	for (ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
	}
	if (maxx==1)
	{
		for (ll i=1;i<=n;i++)
		{
			total=(total*2)%mod;
		}
		for (ll i=1;i<n;i++)
		{
			x=(x+i)%mod;
		}
		y=n;
		printf("%lld",(total-x-y)%mod);
		return 0;
    }
	dfs(1,0);
	printf("%lld",ans%mod);
	return 0;
}
