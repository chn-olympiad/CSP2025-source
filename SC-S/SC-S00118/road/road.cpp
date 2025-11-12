#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, fl;
int f[10005], h[10005], c[15], a[15][100005];
struct edge {
	int u, v, w;
} e[1000005];
bool cmp(edge x, edge y) {
	return x.w < y.w;
}
int find(int x) {
	return (f[x] == x ? x : f[x] = find(f[x]));
}
void merge(int x, int y) {
	f[find(x)] = find(y);
}
int kruskal() {
	int s = 0;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; ++i) {
		if (find(e[i].u) != find(e[i].v)) {
			s += e[i].w;
			merge(e[i].u, e[i].v);
		}
	}
	return s;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	fl = 1;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		if (c[i]) fl = 0;
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			e[++m] = {n + i, j, a[i][j]};
		}
	}
	if (k == 0) {
		for (int i = 1; i <= n; ++i) {
			f[i] = i;
			h[i] = 1;
		}
		cout << kruskal();
		return 0;
	}
	if (fl) {
		for (int i = 1; i <= n + k; ++i) {
			f[i] = i;
			h[i] = 1;
		}
		cout << kruskal();
		return 0;
	}
	return 0;
}