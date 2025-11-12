#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=504580,mod=998244353;
ll n,a[N],sum[N],f[N],J[N];
ll ans=0;

ll kmin(ll x,ll a)
{
	ll ret=1;
	while(a)
	{
		if(a%2==1) ret=ret*x%mod;
		x=x*x%mod;
		a=a/2;
	}
	return ret;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	f[0]=1;
	
	for(ll i=1;i<n;i++)
	{
		if(a[1]+a[i]>a[i+1]) f[i]=(f[i-1]+1)%mod;
		else {
			ll j=0;
			for(ll jj=i;jj>=1;jj--)
			{
				if(a[jj]<=a[i+1]-a[i]) {
					j=jj;
					break;
				}
			}
			
			f[i]=(f[i-1]+f[j-1]+1)%mod;
		}
	}
//	for(int i=1;i<=n;i++) cout<<f[i]<<' ';
	for(ll i=3;i<=n;i++)
	{
		ans=((ans+kmin(2,i-1))%mod-f[i-1]+mod)%mod;
	}
	
	printf("%lld",ans);
	
	return 0;
}
/*
5
1 2 3 4 5
*/