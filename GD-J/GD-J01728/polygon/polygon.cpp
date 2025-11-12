#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],dp[5005][5005],sum[5005][5005],cnt,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	dp[0][0]=1;
	for(long long j=0;j<=5001;j++)sum[0][j]=sum[0][j-1]+dp[0][j],sum[0][j]%=mod;
	for(long long i=1;i<=n;i++){
		for(long long j=5000;j>=a[i];j--){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]],dp[i][j]%=mod;
		}
		for(long long j=a[i]-1;j>=0;j--)dp[i][j]=dp[i-1][j];
		dp[i][5001]=dp[i-1][5001]+sum[i-1][5001]-sum[i-1][5001-a[i]-1]+mod,dp[i][5001]%=mod;
		for(long long j=0;j<=5001;j++)sum[i][j]=sum[i][j-1]+dp[i][j],sum[i][j]%=mod;
	}
	for(long long i=1;i<=n;i++){
		ans+=sum[i-1][5001]-sum[i-1][a[i]]+mod,ans%=mod;
	}
	cout<<ans;
}
