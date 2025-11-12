#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,a[5005],ans,dp[5005][5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=a[n]+1;j++){
			dp[i+1][j]=(dp[i+1][j]+dp[i][j])%998244353;
			dp[i+1][min(a[n]+1,j+a[i+1])]=(dp[i+1][min(a[n]+1,j+a[i+1])]+dp[i][j])%998244353;
		}
		for(int j=a[n]+1;j>=0;j--)
			dp[i][j]=(dp[i][j]+dp[i][j+1])%998244353;
	}
	for(int i=3;i<=n;i++)
		ans=(ans+dp[i-1][a[i]+1])%998244353;
	printf("%lld\n",ans);
}