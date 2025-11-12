#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N=5005,mod=998244353;
ll a[N],n;
ll dp[N];

ll get(ll x){
	return ((x%mod)+mod)%mod;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	sort(a+1,a+n+1);
	
	ll ans=0,cur=1;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		ll sum=0;
		for(int j=0;j<=a[i];j++){
			sum=(sum+dp[j])%mod;
		}
		
		sum=get(cur-sum);
		ans=(ans+sum)%mod;
		cur=(cur*2LL)%mod;
		for(int j=N-1;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	printf("%lld\n",get(ans));
	
	return 0;
}
