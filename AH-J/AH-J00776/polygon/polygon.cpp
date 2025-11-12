#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5010],sum[5010],dp[5010][5010];
bool vis[5010];
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	if(n<3) cout<<0;
	else if(n==3){
		ll ans=0,maxn=0;
		for(ll i=1;i<=n;i++){
			ans+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(ans>maxn*2) cout<<1;
		else cout<<0;
	}
	else{
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ll maxn=0;
			for(ll j=1;j<=n;j++){
				if(dp[i-1][j]<dp[i-1][j]+a[i]){
					dp[i][j]=max(dp[i-1][j],dp[i-1][j]+a[i])%998244353;
					maxn=max(maxn,a[i]);
				}
				else dp[i][j]=max(dp[i-1][j],dp[i-1][j]+a[i])%998244353;
				if(maxn*2<dp[i][j]) ans++;
				ans%=998244353;
			}
			ans%=998244353;
		}	
		ans%=998244353;
		printf("%lld",ans);
	}
	return 0;
}
