#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5e3+5,mod=998244353;
long long n,maxn;
long long a[MAXN];
long long dp[MAXN][MAXN];
int main(){
	// cerr<<(&ed-&st)/1048576.0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]+1);
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=maxn;j++){
			(ans+=dp[i-1][j])%=mod;
		}
		for(int j=0;j<=maxn;j++){
			(dp[i][min(maxn,j+a[i])]+=dp[i-1][j])%=mod;
			(dp[i][j]+=dp[i-1][j])%=mod;
		}
		// for(int j=0;j<=maxn;j++){
		// 	cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		// }
	}
	cout<<ans;
	return 0;
}