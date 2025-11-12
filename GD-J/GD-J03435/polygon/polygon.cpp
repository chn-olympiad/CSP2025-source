#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010;
const int mod=998244353;
int n,a[N];
int dp[N][N*2],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	dp[0][0]=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		for(int j=0;j<=sum;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]) dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
		}
	}
	for(int i=0;i<=n;i++) dp[i][a[i]]=(dp[i][a[i]]+mod-1)%mod;
	sum=a[1]+a[2];
	for(int i=3;i<=n;i++){
		sum+=a[i];
		int tmp=2*a[i]+1-a[i];
		for(int j=tmp;j<=sum-a[i];j++){
			ans=(ans+dp[i-1][j])%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}

