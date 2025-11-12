#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,mod=998244353;
int n,m,ans;
int a[N],dp[N][N],mi[N],dp1[N][N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	int maxn=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++) dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
		for(int j=a[i];j<=maxn;j++){
			dp[i][j]+=dp[i-1][j];
			dp[i][j]%=mod;
			dp[i][j]+=dp[i-1][j-a[i]];
			dp[i][j]%=mod;
		}
		for(int j=0;j<=maxn;j++) dp1[i][j]=(dp1[i][j-1]+dp[i][j])%mod;
	}
	mi[0]=1;
	for(int i=1;i<=n;i++) mi[i]=mi[i-1]*2%mod;
	for(int i=3;i<=n;i++){
		ans+=(mi[i-1]-dp1[i-1][a[i]]+mod+mod)%mod;
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}
