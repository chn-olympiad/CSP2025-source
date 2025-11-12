#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void FileIO (string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int T = (1 << 18) + 5, mod = 998244353;

int n, m, dp[T][20], t, c[510], ans, cnt[510], f[510];
bool s[510];
char ch;
bool flag = 1;

int qmod (int x, int y) {
	int ret = 1;
	while (y) ret = ((y & 1) ? 1ll * ret * x % mod : ret), x = 1ll * x * x % mod, y >>= 1;
	return ret;
}

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	FileIO("employ");
	cin >> n >> m, m = n - m, f[0] = 1;
	for (int i = 1; i <= n; i++) f[i] = 1ll * f[i - 1] * i % mod;
	for (int i = 0; i < n; i++) cin >> ch, s[i] = ch - '0', flag |= s[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	if (n <= 18) {
		t = (1 << n), dp[0][0] = 1;
		for (int i = 0; i < t - 1; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) cnt += (i >> j & 1);
			for (int j = 0; j <= m; j++) if (dp[i][j]) {
				for (int k = 0; k < n; k++)
					if (!(i >> k & 1))
						dp[i + (1 << k)][j + (s[cnt] == 0 || c[k] <= j)] = (dp[i + (1 << k)][j + (s[cnt] == 0 || c[k] <= j)] + dp[i][j]) % mod;
			}
		}
		for (int i = 0; i <= m; i++) ans = (ans + dp[t - 1][i]) % mod;
	} else if (m == 0) {
		ans = f[n];
		if (!flag) ans = 0;
		for (int i = 0; i < n; i++)
			if (c[i] == 0)
				ans = 0;
	} else if (m == n - 1) {
		/*for (int i = 0; i < n; i++) cnt[c[i]]++;
		for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
		for (int i = 0; i < n; i++) {
			ans = (ans + 1ll * A(cnt[i], i))
		}*/
	}
	cout << ans;
	return 0;
}
