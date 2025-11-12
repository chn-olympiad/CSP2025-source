/* CSP 2025 RP++
T4
1 H 10 Min Yu ji 64 */
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5100, MOD = 998244353;
int n, a[N], fg = true, ans = 1;
int main() {
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i), fg &= a[i] == 1, (ans <<= 1) %= MOD;
    if (fg) return cout << (ans - n - n * (n - 1) / 2 - 1 + MOD) % MOD << endl, 0;
    ans = 0;
    for (int i = 0; i < (1 << n); ++i) { 
    	int sum = 0, mx = 0, cnt = 0;
    	for (int j = 0; j < n; ++j) if (i >> j & 1) ++cnt, sum += a[j], mx = max(mx, a[j]);
    	if (sum > 2 * mx && cnt >= 3) ++ans == MOD ? ans = 0 : 0;
	}
	cout << ans << endl;
	return 0;
}
/*
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1048365
*/
// zong fen yu ji: 100 + 100 + 100 + 64 = 364
// xi wang bie gua fen
// qian wan bie gua fen (T3)
