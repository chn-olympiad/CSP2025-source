/* CSP 2025 RP++
T3
50 Min Yu ji 100 */
#include <bits/stdc++.h> 
using namespace std;
constexpr int N = 5e5 + 100;
int n, k, a[N], dp[N], s[N], Map[(1 << 20) + 100]; 
int main() {
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k), dp[0] = -0x3f3f3f3f;
	for (int i = 1; i <= n; ++i) scanf("%d", a + i), s[i] = s[i - 1] ^ a[i];
	for (int i = n; i >= 1; --i) {
		if (a[i] == k) dp[i] = 1;
		dp[i] = max(dp[i + 1] + dp[i], Map[k ^ s[i - 1]] == 0 ? 0 : dp[(Map[k ^ s[i - 1]]) + 1] + 1);
	//	cout << dp[i] << ' ' << Map[k ^ s[i - 1]] << endl;
		Map[s[i]] = i;
	}
	cout << dp[1] << endl;
	return 0;
}
// 2 1 0 3
// 2 3 3 0
