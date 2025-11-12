#include <bits/stdc++.h>
using namespace std;
namespace WorldMachine {
typedef long long ll;
const int N = 1e4 + 15, M = 1e6 + 5, K = 1 << 10;
int n, m, k, fa[N], siz[N], c[10], t[K]; ll sum[K];
struct edge { int u, v, w; } e[M], ae[10][N], E[K][N];
bool cmp(edge a, edge b) { return a.w < b.w; }
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) { if (siz[x] > siz[y]) swap(x, y); fa[x] = y, siz[y] += siz[x]; }
void main() {
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + 1 + m, cmp);
	for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	for (int i = 1, fu, fv; i <= m; i++) {
		if ((fu = get(e[i].u)) == (fv = get(e[i].v))) continue;
		merge(fu, fv), E[0][++t[0]] = e[i], sum[0] += e[i].w;
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i]; for (int j = 1, w; j <= n; j++) cin >> w, ae[i][j] = {n + i + 1, j, w};
		sort(ae[i] + 1, ae[i] + 1 + n, cmp);
	}
	for (int i = 1; i < 1 << k; i++) {
		int lb = 0; for (int j = k - 1; ~j; j--) if (i >> j & 1) sum[i] += c[j], lb = j;
		int p = i ^ 1 << lb, _i = 1, _j = 1, tt = 0;
		while (_i <= t[p] && _j <= n) { if (E[p][_i].w <= ae[lb][_j].w) e[++tt] = E[p][_i++]; else e[++tt] = ae[lb][_j++]; }
		while (_i <= t[p]) e[++tt] = E[p][_i++]; while (_j <= n) e[++tt] = ae[lb][_j++];
		for (int j = 1; j <= n + k; j++) fa[j] = j, siz[j] = 1;
		for (int j = 1, fu, fv; j <= tt; j++) {
			if ((fu = get(e[j].u)) == (fv = get(e[j].v))) continue;
			merge(fu, fv), E[i][++t[i]] = e[j], sum[i] += e[j].w;
		}
	}
	ll ans = LLONG_MAX; for (int i = 0; i < 1 << k; i++) ans = min(ans, sum[i]); cout << ans;
}
}
int main() { return WorldMachine::main(), 0; }
