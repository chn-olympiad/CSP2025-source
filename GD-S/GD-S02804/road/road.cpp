#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
struct Node {
	int v, w;
};

struct Edge {
	int u, v, w;
};

int n, m, k;
long long ans = 1e18;
int c[N], fa[N];
int a[15][N];
Edge edge[5000005];
bitset<15> bs;
vector<Node> G[N];
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

int find(int x) {
	return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

void merge(int x, int y) {
	int r1 = find(x), r2 = find(y);
	
	if (r1 != r2) fa[r1] = r2;
}

void kruskal(int len, long long add) {
	int i;
	
	sort(edge + 1, edge + 1 + len, cmp);
	
	for (i = 1; i <= n; ++i) fa[i] = i;
	
	int cnt = 0;
	long long sum = 0;
	bitset<N> _bs;
	for (i = 1; i <= len; ++i) {
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		
		if (find(u) == find(v)) continue;
		
		if (!_bs.test(u)) ++cnt, _bs.set(u);
		if (!_bs.test(v)) ++cnt, _bs.set(v);
		sum += w;
		merge(u, v);
	}
	
	if (cnt > n - 2) ans = min(ans, sum + add);
}

void dfs(int x, int s) {
	int i, j;
	
	if (x == k + 1) {
		vector<Node> tG[N];
		
		for (i = 1; i <= n; ++i) tG[i] = G[i];
		
		long long add = 0;
		for (i = 1; i <= k; ++i) {
			if (bs.test(i)) {
				for (j = 1; j <= n; ++j) tG[i].push_back({j, a[i][j]});
				add += c[i];
			}
		}
		
		int len = m;
		for (i = 1; i <= k; ++i) {
			for (j = 0; j < tG[i].size(); ++i) edge[++len] = {i, tG[i][j].v, tG[i][j].w};
		}
		
		kruskal(len, add);
		
		return;
	}
	
	if (s < k) bs.set(x), dfs(x + 1, s + 1);
	bs.reset(x), dfs(x + 1, s);
}

int main() {
	int i, j;
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	
	int u, v, w;
	for (i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		G[u].push_back({v, w}), G[v].push_back({u, w});
//		edge[i] = {u, v, w};
	}
	
	for (i = 1; i <= k; ++i) {
		scanf("%d", &c[i]);
		
		for (j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
	}
	
	dfs(1, 0);
	
	printf("%lld", ans);

	return 0;
}

