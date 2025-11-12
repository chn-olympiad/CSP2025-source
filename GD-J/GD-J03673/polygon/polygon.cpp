#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
const int N = 10015;
ll ans,dp[2][N];
int n,a[N],xb;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int o = 0;
	for(int i = 1;i <= n;++i){
		for(int j = a[i]+1;j <= 5001;++j){
			ans = (ans+dp[o^1][j])%mod;
		}
		for(int j = 0;j <= 5001;++j){
			dp[o][j] = dp[o^1][j];
		}
		for(int j = 0;j <= 5001;++j){
			xb = min(5001,j+a[i]);
			dp[o][xb]=(dp[o][xb]+dp[o^1][j])%mod;
		}dp[o][a[i]]=(dp[o][a[i]]+1)%mod;
		o^=1;
	}
	printf("%lld",ans);
	return 0;
}
