#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long MAXN = 1000000;
long long data1[MAXN],n,Max[MAXN],ans,dp[3 * MAXN],sum[MAXN],temp;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for (long long i = 1;i <= n;i ++){
		scanf("%lld",&data1[i]);
	}
	sort(data1 + 1,data1 + 1 + n);
	for (long long i = 1;i <= n;i ++){
		sum[i] = sum[i - 1] + data1[i];
	}
	dp[0] = 1;
	for (long long i = 1;i <= n;i ++){
		temp = 0;
		for (long long j = data1[i] + 1;j <= sum[i - 1];j ++){
			temp = (temp + dp[j]) % mod;
		}
		for (long long j = sum[i];j >= data1[i];j --){
			dp[j] = (dp[j] + dp[j - data1[i]]) % mod;
		}
		if (n >= 3){
			ans = (ans + temp) % mod;
		}
	}
	printf("%lld\n",ans % mod);
	return 0;
}