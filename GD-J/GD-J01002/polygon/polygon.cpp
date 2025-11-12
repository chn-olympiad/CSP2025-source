#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,a[5005],ans=0,c[5005],sum[5005];
ll quickpow(ll b,ll k){
	ll res=1;
	while(k>0){
		if(k&1) res=(res*b%mod);
		b=(b*b%mod);
		k>>=1;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1); 
	c[0]=1;
	sum[0]=1;
	for(ll i=1;i<=5000;i++) sum[i]=1;
	for(ll i=1;i<=n;i++){ 
		ans=(ans+quickpow(2,i-1)-sum[a[i]]+mod)%mod;
		for(ll j=5000;j>=a[i];j--){
			c[j]=(c[j]+c[j-a[i]])%mod;
		} 
		for(ll j=1;j<=5000;j++){
			sum[j]=(sum[j-1]+c[j])%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
