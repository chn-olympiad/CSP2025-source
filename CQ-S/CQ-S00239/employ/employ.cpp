#include<bits/stdc++.h>
using namespace std;
const int N = 510, mod = 998244353;
#define int long long
char s[N];
int n, m, a[N], sum[N], g[N];
int dp[1 << 18][19], c[N][N];
int jc[N];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	jc[0] = 1;
	for (int i = 0; i < N; i ++ ) for (int j = 0; j <= i; j ++ )
		if (!j) c[i][j] = 1; else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	for (int i = 1; i < N; i ++ ) jc[i] = jc[i - 1] * i % mod;
	cin >> n >> m;
	cin >> s + 1;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++ ) sum[a[i]] ++;
	for (int i = 1; i <= n; i ++ ) sum[i] += sum[i - 1];
	if (n <= 18) {
		dp[0][0] = 1;
		for (int j = 0; j < 1 << n; j ++ ) for (int k = 0; k <= n; k ++ ) if (dp[j][k]) for (int l = 0; l < n; l ++ ) if (!(j >> l & 1)) {
			int C = __builtin_popcount(j);
			if (s[C + 1] == '0' || a[l + 1] <= k) dp[j | (1 << l)][k + 1] = (dp[j | (1 << l)][k + 1] + dp[j][k]) % mod;
			else dp[j | (1 << l)][k] = (dp[j | (1 << l)][k] + dp[j][k]) % mod;
		}
		int ans = 0;
		for (int i = 0; i <= n - m; i ++ ) ans = (ans + dp[(1 << n) - 1][i]) % mod;
		cout << ans;
		return 0;
	}
	if (m == 1) {
		int ans = 1, num = 0;
		for (int i = 1; i <= n; i ++ ) {
			if (a[i] == 0) num ++;
			else {
				if (sum[i - 1] < i - 1) {
					ans = 0;
					break;
				}
				ans = ans * (sum[i - 1] - i + 1) % mod;
			}
		}
		cout << ans * jc[num] % mod;
		return 0;
	}
	if (m == n) {
		for (int i = 1; i <= n; i ++ ) if (!a[i] || s[i] == '0') {
			cout << 0;
			return 0;
		}
		cout << jc[n];
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i ++ ) if (s[i] == '1') cnt ++;
	if (cnt == n) {
		g[0] = 1;
		for (int i = 1; i <= n; i ++ ) g[i] = g[i - 1] * max(0ll, sum[i - 1] - i + 1) % mod;
		int ans = 0;
		for (int i = 0; i <= n - m; i ++ ) {
			int res = 0;
			for (int j = i; j <= n; j ++ ) res = (res + ((j - i & 1) ? -1 : 1) * c[j][i] * c[n][j] % mod * g[j] % mod * jc[n - j]) % mod;
			ans = (ans + res) % mod;
		}
		cout << (ans + mod) % mod;
		return 0;
	}
	return 0;
}
