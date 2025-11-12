#include<bits/stdc++.h>
#define ll long long
using namespace std;


const ll N=5e5+100;
ll n,KK,ans=INT_MIN;
ll a[N],b[N],dp[N];


signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);


	scanf("%lld%lld",&n,&KK);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=b[i-1]^a[i];
	}

	
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=i;j++){
			dp[i]=max(dp[i],dp[j-1]+((b[i]^b[j-1])==KK));
		}
	}
	
	
	for(ll i=1;i<=n;i++){
		ans=max(dp[i],ans);
	}
	
	
	printf("%lld\n",ans);
	
	
	return 0;
}
