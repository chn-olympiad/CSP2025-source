#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 500 + 10, maxm = 50000 + 10, mod = 998244353;
int a[maxm], dp[maxn][maxm], S, Mx, sumdp[maxm];
const int maxT = 5000 + 10;
int Tdp[maxT][maxT], Tsumdp[maxT];
signed main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		S += a[i], Mx = max(Mx, a[i]);
	} int ans = 0; dp[0][0] = sumdp[0] = 1;
	sort(a + 1, a + n + 1);
	if (n > 500) {
		int Tans = 0; Tdp[0][0] = Tsumdp[0] = 1;
		for (int i = 1; i <= n; i ++) {
			for (int j = a[i]; j <= S; j ++) {
				Tdp[i][j] = Tsumdp[j - a[i]];
			}
			for (int j = 2 * a[i] + 1; j <= S; j ++) {
				Tans = (1ll * Tans + 1ll * Tdp[i][j]) % mod;
			}
			for (int j = 0; j <= S; j ++) {
				Tsumdp[j] = (1ll * Tsumdp[j] + 1ll * Tdp[i][j]) % mod;
			}
		}
		cout << Tans;
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = a[i]; j <= S; j ++) {
			dp[i][j] = sumdp[j - a[i]];
		}
		for (int j = 2 * a[i] + 1; j <= S; j ++) {
			ans = (1ll * ans + 1ll * dp[i][j]) % mod;
		}
		for (int j = 0; j <= S; j ++) {
			sumdp[j] = (1ll * sumdp[j] + 1ll * dp[i][j]) % mod;
		}
	}
	cout << ans;
	return 0;
}
