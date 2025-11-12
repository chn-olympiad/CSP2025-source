#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAX_N = 505;

int n, m, c[MAX_N];
string s;

int dp[1 << 19][19];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (n > 18) {
		cout << 0 << '\n';
		return 0;
	}

	dp[0][0] = 1;
	for (int S = 0; S < 1 << n; S++)
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 1; j <= n; j++)
				if (S >> j - 1 & 1)
					cnt++;
			if (i > cnt)
				break;
			
			for (int j = 1; j <= n; j++)
				if (!(S >> j - 1 & 1)) {
					int T = S | (1 << j - 1);
					if (s[cnt] == '0' || cnt - i >= c[j])
						dp[T][i] = (dp[T][i] + dp[S][i]) % MOD;
					else
						dp[T][i + 1] = (dp[T][i + 1] + dp[S][i]) % MOD;
				}
		}
	
	int ans = 0;
	for (int i = m; i <= n; i++)
		ans = (ans + dp[(1 << n) - 1][i]) % MOD;
	cout << ans << '\n';
	return 0;
}
