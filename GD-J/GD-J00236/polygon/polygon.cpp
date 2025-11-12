#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,dp[5005][5005],ans,a[5005];
const int mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1),dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=5001;j++) ans=(ans+dp[i-1][j])%mod;
		for(int j=0;j<=5001;j++) dp[i][j]=dp[i-1][j];
		for(int j=0;j<=5001;j++) dp[i][min(j+a[i],5001ll)]=(dp[i][min(j+a[i],5001ll)]+dp[i-1][j])%mod;
	}
	return printf("%lld\n",ans),0;
}
