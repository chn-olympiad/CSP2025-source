#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5009, N1 = 509, M1 = 109, K1 = 50009, Q = 998244353;
int n, a[N], sm[N], dp[M1][K1], t[2][M1][K1], ans, mx[N];
void dfs(int x, int Mx, int Sm) {
	if (x > n) {
		ans += (Sm > (Mx << 1));
		return;
	}
	dfs(x + 1, Mx, Sm);
	dfs(x + 1, max(Mx, a[x]), Sm + a[x]);
}
inline int myn(int x, int y) { return x > y ? y : x; }
inline int myx(int x, int y) { return x < y ? y : x; }
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	if (n <= 20) {
		dfs(1, 0, 0);
		cout << ans;
		exit(0);
	}
	if (mx[n] == 1) {
		ans = 1;
		for (int i = 1; i <= n; i++) ans = (ans << 1) % Q;
		cout << ans - n - ((n * (n - 1)) >> 1) - 1;
		exit(0);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sm[i] = sm[i - 1] + a[i], mx[i] = myx(mx[i - 1], a[i]);
	for (int i = 1; i <= n; ++i) {
		bool z = i & 1, y = z ^ 1; int ai = a[i];
		for (int j = 0; j <= mx[i]; ++j) {
			t[y][j][0] = 1; int fr = myn(j, mx[i - 1]), f = -ai;
			for (int k = 0; k <= sm[i]; ++k) {
				if (k >= ai && j >= ai)
					dp[j][k] = (dp[j][k] + t[y][fr][f]) % Q;
				//printf("dp[%lld][%lld][%lld]=%lld\n", i, j, k, dp[z][j][k]);
				if (i == n) {
					if (k > (j << 1)) ans = (ans + dp[j][k]) % Q;
				}
				else if (j != 0) t[z][j][k] = (t[z][j - 1][k] + dp[j][k]) % Q;
				else t[z][j][k] = dp[j][k];
				f++;
			}
		}
	}
	cout << ans;
}/*

*/