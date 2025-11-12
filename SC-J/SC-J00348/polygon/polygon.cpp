#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
const int N=5e3+10;
ll n,a[N];
ll modd(ll x)
{
	return (x+mod)%mod;
}
ll jc[N];
ll inv[N];
ll jc_inv[N];
ll c(ll n,ll m)
{
	return modd(modd(jc[n]*jc_inv[m])*jc_inv[n-m]);
}
ll ans=0;
bool vis=true;
int main()
{
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) vis=false;
	} 
	if(vis)
	{
		jc[0]=jc[1]=1;
		inv[1]=1;
		jc_inv[0]=jc_inv[1]=1;
		for(int i=2;i<=N;i++)
		{
			jc[i]=modd(jc[i-1]*i);
			inv[i]=modd(mod-mod/i*modd(inv[mod%i])%mod);
			jc_inv[i]=modd(jc_inv[i-1]*inv[i]);
		}
		ans=0;
		for(int i=3;i<=n;i++)
		{
			ans=c(n,i)+ans;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<(1<<n);i++)
	{
		ll maxx=0,sum=0,k;
		for(int j=1;j<=n;j++)
		{
			if((i>>(j-1))&1)
			{
				maxx=max(maxx,a[j]);
				sum+=a[j];
				k++;
			}
		}
		if(k<3||sum<=(maxx*2)) continue;
		ans=modd(ans+1);
	}
	cout<<ans;
	return 0;	
} 