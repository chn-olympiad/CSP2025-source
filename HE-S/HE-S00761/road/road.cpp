#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1.5e6 + 10;
struct edge{
	int u, v, w;
}e[N];
int fa[N];
int c[N];
int h[15][N];
int f[1005][1005];
inline int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
inline bool cmp (edge a, edge b) {
	return a.w< b.w;
}
int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	int tot = m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) f[i][j] = 1e9;
	}
	bool key = 1;
	for (int j = 1; j <= k; j++) {
		int x;
		cin >> x;
		c[j] = x;
		key &= (x == 0);
		for (int i = 1; i <= n; i++) cin >> h[j][i];
	}
	ll ans = 1e18;
	ll cnt = 0, sum = 0;
	int g = k + n;
	if (key) {
		for (int j = 1; j <= k; j++) {
			for (int i = 1; i <= n; i++) {
				for (int p = i + 1; p <= n; p++) f[i][p] = f[p][i] = min(f[i][p], h[j][i] + h[j][p]);
			}
		}
	}
	else {
		for (int j = 1; j <= k; j++) {
			for (int i = 1; i <= n; i++) e[++tot].u = j + n, e[tot].v = i, e[tot].w = h[j][i];
		}
		sort(e + 1, e + tot + 1, cmp);
		ans = 1e18;
		for (int s = 0; s < (1 << k); s++) {
			cnt = 0, sum = 0;
			for (int i = 1; i <= g; i++) fa[i] = i;
			for (int i = 0; i < k; i++) {
				if (s >> i & 1) sum += c[i + 1];
			}
			if (sum >= ans) continue;
			int num = __builtin_popcount(s);
			bool vip = 1;
			for (int i = 1; i <= tot; i++) {
				int u = e[i].u, v = e[i].v;
				if (u > n && (!(s >> (u - n - 1)))) continue;
				if (v > n && (!(s >> (v - n - 1)))) continue;
				int x = find(u), y = find(v);
				if (x == y) continue;
				fa[x] = y;
				sum += e[i].w;
				if (sum >= ans) {
					vip = 0;
					break;
				}
				cnt++;
			}
			if (vip) ans = min(ans, sum);
		}
		cout << ans << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			e[++tot].u = i;
			e[tot].v = j;
			e[tot].w = f[i][j];
		}
	}
	sort(e + 1, e + tot + 1, cmp);
	for (int i = 1; i <= g; i++) fa[i] = i;
	for (int i = 1; i <= tot; i++) {
		int u = e[i].u, v = e[i].v;
		int x = find(u), y = find(v);
		if (x == y) continue;
		fa[x] = y;
		sum += e[i].w;
		if (sum >= ans) break;
		cnt++;
		if (cnt == n - 1) break;
	}
	ans = min(ans, sum);
	cout << ans << '\n';
}
