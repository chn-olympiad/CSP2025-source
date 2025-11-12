#include <bits/stdc++.h>
using namespace std;

const int N = 10010, K = 15;
struct Edge {
	int x, y, l;
	Edge(int _x, int _y, int _l) {
		x = _x, y = _y, l = _l;
	}
	bool operator <(const Edge &A) {
		return l < A.l;
	}
};
int n, m, k, c[K], a[K][N];
vector<Edge> edge;
bool b[N];

struct DSU {
	std::vector<int> fa;
	DSU() {}
	DSU(int n) {
		init(n);
	}
	void init(int n) {
		fa.resize(n + 1);
		for (int i = 1; i <= n; i++)
			fa[i] = i;
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	bool Union(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) return false;
		fa[fx] = fy;
		return true;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge.push_back(Edge(u, v, w));
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			edge.push_back(Edge(n + i, j, a[i][j]));
		}
	}
	sort(edge.begin(), edge.end());
	DSU dsu(n + k);
	long long ans = 0;
	for (Edge p : edge) {
		if (!dsu.same(p.x, p.y)) {
			dsu.Union(p.x, p.y);
			ans += p.l;
		}
	}
	printf("%lld\n", ans);
}
