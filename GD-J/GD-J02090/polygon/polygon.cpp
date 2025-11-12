#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define enl putchar('\n')
#define ys puts("YES")
#define pii pair<int, int>
using namespace std;
const int MAX=5e2+10, MAXM=5e4+10, MOD=998244353;
int n, a[MAX], dp[MAX][MAXM][2], sum[MAX][MAXM][2];
ll ans;
ll qpow(ll a, ll b) {
	ll res=1;
	while (b) {
		if (b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1; 
	}
	return res;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i=1;i<=min(n, MAX-1);i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	if (n>500&&a[n]==1) return printf("%lld", ((((qpow(2, n)-n-1)%MOD+MOD)%MOD-n*(n-1)%MOD*qpow(2, MOD-2)%MOD)%MOD+MOD)%MOD), 0;
	sum[0][0][0]=1;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<MAXM;j++) {
			dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%MOD;
			if (j>a[i]<<1) dp[i][j][1]=sum[i][j-a[i]][0];
			sum[i][j][0]=(sum[i-1][j][0]+sum[i-1][j][1])%MOD;
			if (j>=a[i]) sum[i][j][1]=(sum[i-1][j-a[i]][0]+sum[i-1][j-a[i]][1])%MOD;
		}
	}
	for (int i=0;i<MAXM;i++) ans=(ans+(dp[n][i][0]+dp[n][i][1])%MOD)%MOD;
	printf("%lld", ans);
	return 0;
}
