#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll const maxn=5000;
ll const mod=998244353;
ll const maxk=6000;
ll a[maxn+1];
ll n;
ll f[maxk+1];
ll g2[maxk+1];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	g2[min(a[1]+a[2],maxk)]++;
	ll ans=0;
	ll qz=a[1]+a[2];
	for(ll i=3;i<=n;i++){
		for(ll j=a[i]+1;j<=maxk;j++){
			ans+=f[j];
			ans+=g2[j];
			ans%=mod;
		}
		for(ll j=maxk;j>=0;j--){
			ll g=min(maxk,j+a[i]);
			f[g]+=f[j];
			f[g]+=g2[j];
			f[g]%=mod;
		}
		for(ll j=1;j<i;j++){
			g2[min(maxk,a[i]+a[j])]++;
		}
		qz+=a[i];
	}
	printf("%lld",ans);
	
	
	return 0;
}
