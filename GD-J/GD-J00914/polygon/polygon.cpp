#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3,mod=998244353;
ll n;
ll a[N+5];
ll dp[N+5][N+5];
ll ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(ll i=0;i<=N;i++) dp[i][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=N;j++){
			if(j-a[i]>=0){
				dp[i][j]+=dp[i-1][j-a[i]];
				dp[i][j]%=mod;
			}
			dp[i][j]+=dp[i-1][j];
			dp[i][j]%=mod;
		}
		for(ll j=0;j<=N;j++){
			if(j+a[i]>N) dp[i][N+1]+=dp[i-1][j],dp[i][N+1]%=mod;
		}
		dp[i][N+1]+=dp[i-1][N+1]*2%mod,dp[i][N+1]%=mod;
	}
	for(ll i=n;i>=1;i--){
		for(ll j=a[i]+1;j<=N+1;j++){
			ans+=dp[i-1][j];
			ans%=mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
