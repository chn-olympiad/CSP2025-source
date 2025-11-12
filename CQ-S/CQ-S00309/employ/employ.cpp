#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n, m, c[505], dp[505][505], sum[505], st, ans, num[505], fac[505][505];
string s;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    s = " " + s;
	int tttt = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
		if (c[i] <= 0) {
			tttt ++;
			continue;
		}
		// for (int j = 1; j <= n; j ++) {
		// 	change(1, 1, n, 0, c[i] - 1, 1, j);
		// }
		for (int j = 1; j <= c[i] - 1; j ++) {
			num[j] ++;
		}
    }
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			for (int k = n; k >= n - j + 1; k --) {
				fac[i][j] *= k;
				fac[i][j] %= MOD;
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1];
		if (s[i] == '1') {
			sum[i] ++;
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (sum[i] >= m) {
			st = i;
			break;
		}
	}
	if (st == 0) {
		cout << "0";
		return 0;
	}
    for (int i = 1; i <= n; i ++) {
        for (int j = max(i, tttt); j <= n; j ++) {
			if (s[i] == '0') {
				int l = n - num[i - sum[i]], ll = n - num[i - 1 - sum[i - 1]];
				for (int k = 1; k <= l - ll; k ++) {
					dp[i][j] += fac[num[i - sum[i]]][k];
					dp[i][j] %= MOD;
				}
				dp[i][j] %= MOD;
			} else {
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] %= MOD;
			}
        }
    }
	for (int i = st; i <= n; i ++) {
        for (int j = max(i, tttt); j <= n; j ++) {
			ans += dp[i][j];
			ans %= MOD;
        }
    }
	cout << ans;
    return 0;
}