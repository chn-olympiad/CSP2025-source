#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define mems(x, v) memset((x), (v), sizeof (x))
#define mcpy(x, y) memcpy((x), (y), sizeof (x))
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

const int N = 505, mod = 998244353;
int a[N], c[N], ze[N], S[N], dp[20][20][1 << 18];
int main() {
	freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%1d", &a[i]), ze[i] = ze[i - 1] + !a[i];
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]), S[c[i]]++;
	for (int i = 1; i <= n; i++) S[i] += S[i - 1];
	sort(c + 1, c + n + 1);
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) for (int j = 0; j <= min(i - 1, n - m); j++) for (int S = 0; S < (1 << n); S++) if (dp[i - 1][j][S]) {
		if (!a[i]) {
			(dp[i][j + 1][S] += dp[i - 1][j][S]) %= mod;
			// for (int x = 1; x <= n; x++) if (!(S >> (x - 1) & 1)) {
			// 	(dp[i][j + 1][S | (1 << (x - 1))] += dp[i - 1][j][S]) %= mod;
			// }
		}
		else {
			for (int x = 1; x <= n; x++) if (!(S >> (x - 1) & 1)) {
				(dp[i][j + (c[x] <= j)][S | (1 << (x - 1))] += dp[i - 1][j][S]) %= mod;
			}
		}
	}
	int ans = 0; for (int i = 0; i <= n - m; i++) for (int S = 0; S < (1 << n); S++) (ans += dp[n][i][S]) %= mod;
	int fac = 1; for (int i = 1; i <= ze[n]; i++) fac = 1ll * fac * i % mod;
	cout << 1ll * ans * fac % mod;
	return 0;
}
/*绝望了
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define mems(x, v) memset((x), (v), sizeof (x))
#define mcpy(x, y) memcpy((x), (y), sizeof (x))
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

const int N = 505, mod = 998244353;
int C[N][N], fac[N], a[N], c[N], ze[N], S[N], SS[N], dp[20][20][20][20];
int main() {
	//freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
	int n, m; scanf("%d%d", &n, &m);
	fac[0] = 1; for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	for (int i = 0; i <= n; i++) {C[i][0] = 1; for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;}

	for (int i = 1; i <= n; i++) scanf("%1d", &a[i]), ze[i] = ze[i - 1] + !a[i];
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]), S[c[i]]++;
	for (int i = 1; i <= n; i++) SS[i] = SS[i - 1] + S[i];
	sort(c + 1, c + n + 1);
	dp[0][0][0][0] = 1;
	for (int i = 1; i <= n; i++) for (int j = 0; j <= min(i - 1, n - m); j++) for (int k = 0; k < n; k++) for (int u = 0; u <= n; u++) if (dp[i - 1][j][k][u]) {
		if (!a[i]) {
			//(dp[i][j + 1][k + S[j + 1]][u] += dp[i - 1][j][k][u]) %= mod;
			for (int x = 0; x <= min(S[j + 1], u); x++) {
				int &t = dp[i][j + 1][k + S[j + 1] - x][u - x];
				t = (t + 1ll * C[u][x] * C[S[j + 1]][x] % mod * fac[x] % mod * dp[i - 1][j][k][u]) % mod;
			}
		}
		else {
			if (S[j] >= k) {
				dp[i][j + 1][k - 1][u] = (dp[i][j + 1][k - 1][u] + 1ll * k * dp[i - 1][j][k][u]) % mod;
				(dp[i][j][k][u + 1] += dp[i - 1][j][k][u]) %= mod;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n - m; i++) for (int j = 0; j <= n; j++) for (int u = 0; u <= n; u++) if (dp[n][i][j][u]) {
		ans = (ans + 1ll * C[n - SS[j]][u] * fac[u] % mod * dp[n][i][j][u]) % mod;
	}
	int fac = 1; for (int i = 1; i <= ze[n]; i++) fac = 1ll * fac * i % mod;
	cout << 1ll * ans * fac % mod;
	return 0;
}
*/