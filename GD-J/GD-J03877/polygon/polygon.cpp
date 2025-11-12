#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=998244353;
ll dp[5005],n,a[5005],qz[5005];
ll fm(ll x,ll m){
	ll re=1,dc=x;
	while(m){
		if(m&1){
			re=re*dc%mod;
		}
		dc=dc*dc%mod;
		m>>=1;
	}
	return re;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
//		a[i]=1;
	}
	sort(a+1,a+1+n);
	ll ans=0;
	dp[0]=qz[0]=1;
	for(ll i=1;i<=5000;i++){
		qz[i]=dp[i]+qz[i-1];
	}
	for(ll i=1;i<=n;i++){
		
		if(i>=3){
			ll dz=fm(2,i-1)-qz[a[i]];
//			for(ll j=0;j<=a[i];j++){
//				cout<<dp[j]<<' ';
//			}
//			cout<<endl;
//			cout<<fm(2,i-1)<<' '<<qz[a[i]]<<' '<<i-1<<' '<<qz1[a[i]]<<"|:"<<dz<<endl;
			ans=(ans+dz)%mod;
		}
		for(ll j=5000;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		qz[0]=1;
		for(ll j=1;j<=5000;j++){
			qz[j]=(dp[j]+qz[j-1])%mod;
		}
	}
	ans=(ans%mod+mod)%mod;
	printf("%lld",ans);
	return 0;
}
