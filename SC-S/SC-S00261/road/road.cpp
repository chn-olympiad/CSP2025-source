#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 1e6 + 5;
int n, m, k, fa[N], ans, c[M], l = 0;
struct node {
	int u, v, w;
}g[M * 5];
void add (int u, int v, int w) {
	l++;
	g[l].u = u;
	g[l].v = v;
	g[l].w = w;
}
bool cmp (node x, node y) {
	return x.w < y.w;
}
int find (int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	fa[x] = y;
}
bool check() {
	for (int i = 1; i < n; i++) {
		if (find(i) != find(i + 1)) {
			return false;
		}
	}
	return true;
}
void kruskal () {
	int cnt = 1;
	for (int i = 1; i <= l; i++) {
		if (check()) {
			break;
		}
		int x = find(g[i].u), y = find(g[i].v);
		if (x != y) {
			merge(x, y);
			ans += g[i].w;
//			cout << "------------" << g[i].u << " " << g[i].v << " " << g[i].w << '\n';
			cnt++; 
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n * 2; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			int w;
			cin >> w;
			add(j, k + n, w);
		}
	}
	sort(g + 1, g + l + 1, cmp);
	kruskal();
	cout << ans << '\n';
	return 0;
}