#include <bits/stdc++.h>
#define int long long
#define il inline 
using namespace std;
const int N = 18, M = 505, p = 998244353;
int fac[M];
void init(int n = 500) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % p;
}
int n, m, a[M], c[M];
char ch;
int ans = 0;
bool vis[M];
void dfs(int i = 1, int cnt = 0) {
	if (i - cnt - 1 >= m) {
		ans = (ans + fac[n - i + 1]) % p;
		return ;
	}
	if (n - cnt < m) return ;
	if (i > n) return ;
	for (int j = 1; j <= n; j++) if (!vis[j]) {
		vis[j] = 1;
		dfs(i + 1, cnt + (cnt >= c[j] or a[i] == 0));
		vis[j] = 0;
	}
}
int f[1 << N][N + 5];
void add(int& x, int v) {
	x = (x + v >= p ? x + v - p : x + v);
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ch;
		a[i] = ch - 48;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (n <= 18) {
		f[0][0] = 1;
		for (int s = 1; s < (1 << n); s++) {
			int ppc = __builtin_popcount(s);
			for (int j = 0; j <= n; j++) {
				for (int i = 0; i < n; i++) if ((s >> i) & 1) {
					add(f[s][j + (j >= c[i + 1] or a[ppc] == 0)], f[s ^ (1 << i)][j]);
				}
			}
		}
		for (int i = 0; i <= n - m; i++) {
			add(ans, f[(1 << n) - 1][i]);
		}
		cout << ans;
	} else {
		dfs(); 
		cout << ans;
	}
}
