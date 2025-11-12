#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define int long long
using namespace std;
#define pii pair<int, int>
#define ppi pair<int, pair<int, int> >
#define mkp(a, b) make_pair((a), (b))
bool condA = 1;
struct Graph {
	vector<pii> G[10005];
	Graph() {
		for(int i = 1; i <= 10000; i++) {
			G[i].shrink_to_fit();
		}
	}
} g, ext, emp;
int cost[10][10005];
int fa[10005];
int findFa(int u) {
	if(fa[u] == u) return u;
	return fa[u] = findFa(fa[u]);
}
void merge(int x, int y) {
	int rx = findFa(x);
	int ry = findFa(y);
	if(rx == ry) return ;
	fa[rx] = ry;
}
void Kruskal(int n) {
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	priority_queue<ppi, vector<ppi>, greater<ppi> > q;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < g.G[i].size(); j++) {
			q.push(mkp(g.G[i][j].second, mkp(i, g.G[i][j].first)));
		}
	}
	int cnt = 0;
	while(!q.empty()) {
		int u = q.top().second.first;
		int v = q.top().second.second;
		//printf("%d %d %d\n", u, v, q.top().first);
		int ru = findFa(u);
		int rv = findFa(v);
		if(ru != rv) {
			merge(ru, rv);
			cnt++;
			ans += q.top().first;
			if(cnt == n - 1) break;
		}
		q.pop();
	}
	printf("%lld\n", ans);
}
signed main() {
	//printf("%d\n", mkp(4, 5) > mkp(5, 4));
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		g.G[u].push_back(mkp(v, w));
	}
	for(int i = 1; i <= k; i++) {
		bool c1 = 0;
		int rt;
		for(int j = 0; j <= n; j++) {
			scanf("%lld", &cost[i][j]);
			if(j == 0 && cost[i][j] == 0) c1 = 1;
			if(j != 0 && cost[i][j] == 0) rt = j;
		}
		//printf("%d %d\n", i, rt);
		for(int j = 1; j <= n; j++) {
			if(rt != j) g.G[rt].push_back(mkp(j, cost[i][j]));
		//	printf("- %d %d %d %d\n", rt, j, i, cost[i][j]);
		}
	}
	if(k == 0) Kruskal(n);
	else if(condA) {
		Kruskal(n);
	}
	return 0;
}
