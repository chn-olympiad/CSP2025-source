#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 2e6 + 20, M = 2e6 + 20, K = 20;
typedef pair <int, int> pii;
int n, m, k;
int c[K], a[K][N];
struct edge {
	int u, v, w;
} g[M];
int f[N];
int find (int x) {
	return (x == f[x] ? x : f[x] = find (f[x]));
}
int main () {
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
		cin >> g[i].u >> g[i].v >> g[i].w;
	bool flag1 = true;
	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		if (c[i]) flag1 = false;
		for (int j = 1; j <= n; j ++) {
			cin >> a[i][j];
			if (a[i][j]) flag1 = false;
		}
	}
	if (flag1 && k) {
		cout << 0;
		return 0;
	}
	long long Min = 1e18;
	int qwq[20], tot, cnt;
	for (int S = 0; S < (1 << k); S ++) {
		tot = 0;
		bool flag = true;
		long long ans = 0;
		for (int i = 0; i < k; i ++)
			if ((1 << i) & S) {
				qwq[++ tot] = i + 1, ans += c[i + 1];
				if (ans > Min) {
					flag = false;
					break;
				}
				for (int j = 1; j <= n; j ++)
					g[m + (tot - 1) * n + j] = {m + tot, j, a[i + 1][j]};
			}
//		cout << "The TOT is " << tot << '\n';
		for (int i = 1; i <= n + tot; i ++)
			f[i] = i;
		sort (g + 1, g + m + tot * n + 1, [](edge a, edge b) {
			return a.w < b.w;
		});
		cnt = 0;
		for (int i = 1; i <= m + tot * n; i ++) {
			int u = g[i].u, v = g[i].v, w = g[i].w;
			if (find (u) == find (v)) continue;
			f[find (u)] = find (v);
			cnt ++;
//			cout << u << " " << v << " " << w << '\n';
			ans += 1ll * w;
			if (ans > Min) {
				flag = false;
				break;
			}
			if (cnt == n + tot - 1) break;
		}
//		cout << ans << "---------------\n";
		if (flag) Min = min (Min, ans);
	}
	cout << Min;
	return 0;
} 
