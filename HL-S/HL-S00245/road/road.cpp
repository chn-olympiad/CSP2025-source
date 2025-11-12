// Respect to Nailoong
#include <bits/stdc++.h>
#define int long long
#define fin(x) freopen(#x ".in", "r", stdin);
#define fout(x) freopen(#x ".out", "w", stdout);
#define file(x) fin(x); fout(x);
using namespace std;
constexpr int K = 15;
constexpr int L = 1024;
constexpr int N = 10015;
constexpr int M = 2e6 + 5;
int n, m, k, idx, val[K], fa[N], siz[N], e[K][N], E[L][N], cnt[L], ans;
struct Node {
	int x, y, z;
	bool operator < (const Node &another) const { return z < another.z; }
} g[M]; 
int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
void merge(int x, int y) {
	x = getfa(x), y = getfa(y);
	if (siz[x] > siz[y]) swap(x, y);
	siz[y] += siz[x], fa[y] = x;
}
signed main() {
	file(road);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) ++idx, cin >> g[idx].x >> g[idx].y >> g[idx].z;
	sort(g + 1, g + m + 1);
	for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; ++i) if (getfa(g[i].x) != getfa(g[i].y)) merge(g[i].x, g[i].y), ans += g[i].z, E[0][++cnt[0]] = i;
	for (int i = 1; i <= k; ++i) {
		cin >> val[i];
		for (int j = 1; j <= n; ++j) ++idx, g[idx].x = n + i, g[idx].y = j, cin >> g[idx].z, e[i][j] = idx;
		sort(e[i] + 1, e[i] + n + 1, [&] (int x, int y) { return g[x] < g[y]; });
	}
	for (int S = 1; S < (1 << k); ++S) {
		int p, q, now = 0;
		for (int i = 0; i < k; ++i) if ((S >> i) & 1) now += val[i + 1];
		for (int i = 0; i < k; ++i) if ((S >> i) & 1) { p = i + 1, q = S ^ (1 << i); break; }
		for (int i = 1; i <= n + k; ++i) fa[i] = i, siz[i] = 1;
		int i = 1, j = 1;
		while(i <= n || j <= cnt[q]) {
			if (j > cnt[q] || (i <= n && g[e[p][i]] < g[E[q][j]])) {
				int u = g[e[p][i]].x, v = g[e[p][i]].y;
				if (getfa(u) != getfa(v)) merge(u, v), now += g[e[p][i]].z, E[S][++cnt[S]] = e[p][i];
				++i; continue; 
			}
			else {
				int u = g[E[q][j]].x, v = g[E[q][j]].y;
				if (getfa(u) != getfa(v)) merge(u, v), now += g[E[q][j]].z, E[S][++cnt[S]] = E[q][j];
				++j; continue; 
			}
		}
		ans = min(ans, now);
	}
	cout << ans;
}
