#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
const int mod = 998244353;
int a[N];
int dp[N], cnt[N][N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 5000; j > a[i]; j--) {
			if (dp[j - a[i]] > 0) {
				dp[j] += dp[j - a[i]];
			}
			cnt[i][j] = dp[j];
		}
		dp[a[i]] += dp[0];
	}
	long long tot = 0;
	for (int i = 3; i <= n; i++) {
		for (int j = 5000; j > a[i]; j--) {
			tot = (tot + cnt[i - 1][j]) % mod;
		}
	}
	printf("%lld", tot);
	return 0;
}

//ak ioi
//qwq
//What can I say, Mamba out!
