#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500000];
ll g[15500][5];
const ll mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll mx=a[n]+1,ans=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=a[i]+1;j<=mx;j++)
		{
			ans+=g[j][2];
			ans%=mod;
		}
		for(ll k=2;k>=1;k--)
		{
			for(ll j=mx;j>=0;j--)
			{
				g[min(j+a[i],mx)][2]+=g[j][k];
				g[min(j+a[i],mx)][2]%=mod;
			}
		}
		g[a[i]][1]++;
		g[a[i]][1]%=mod;
	}
	printf("%lld",ans);
	return 0;
}
