#include <bits/stdc++.h>
using namespace std;

const int N = 505, P = 998244353;

int n, m;
char s[N];
int c[N], cnt[N];

void inc(int &x, int y) { if ((x += y) >= P) x -= P;}
int mul(int x, int y) { return 1ll * x * y % P;}

int dp[2][N][N];
int fac[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> s[i];
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		cnt[c[i]]++;
	}
	for (int i = n; i >= 0; --i) cnt[i] += cnt[i + 1];
	
	for (int i = 0; i <= n - m; ++i) dp[n & 1][i][0] = 1;
	for (int i = n; i >= 1; --i) {
		int cur = (i & 1);
		memset(dp[cur ^ 1], 0, sizeof dp[cur ^ 1]);
		if (s[i] == '1') {
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k <= n; ++k) {
					if (k < cnt[j + 1]) inc(dp[cur ^ 1][j][k + 1], mul(cnt[j + 1] - k, dp[cur][j][k]));
					if (j && k < cnt[j]) inc(dp[cur ^ 1][j - 1][k + 1], mul(cnt[j] - k, P - dp[cur][j][k]));
					if (j) inc(dp[cur ^ 1][j - 1][k], dp[cur][j][k]);
				}
			}
		} else {
			for (int j = 1; j <= n; ++j) {
				for (int k = 0; k <= n; ++k) {
					inc(dp[cur ^ 1][j - 1][k], dp[cur][j][k]);
				}
			}
		}
	}
	
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
	int ans = 0;
	for (int i = 0; i <= n; ++i) inc(ans, mul(dp[0][0][i], fac[n - i]));
	cout << ans << endl;
	
	return 0;
}