#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,sum,ans;
long long a[5005],dp[2][20000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	dp[0][0]=1;
	for (int i=1; i<=n; i++){
		for (int j=0; j<=sum; j++){
			if (dp[0][j]){
				dp[1][j+a[i]]=(dp[1][j+a[i]]+dp[0][j])%mod;
				dp[1][j]=(dp[1][j]+dp[0][j])%mod;
			}
		}
		for (int j=0; j<=sum; j++){
			dp[0][j]=dp[1][j];
			if (j>a[i]*2&&dp[0][j]&&i>=3) ans=(ans+dp[0][j])%mod;
			dp[1][j]=0;
		}
	}
	cout<<ans%mod;
	return 0;
}
