#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxn = 1e4 + 5;
const int maxm = 1e6 + 5;

int n, m, k;
struct Edge {
	int u, v, w;
	bool operator< (const Edge &rhs) const {
		return w < rhs.w;
	}
} E[maxm];

int e[15][maxn], pos[15][maxn];
int cnt[15];
bool vis[15];
struct Node {
	int x, y;
	LL w;
	Node() = default;
	Node(int _x, int _y, LL _w) : x(_x), y(_y), w(_w) {}
	bool operator< (const Node &rhs) const {
		return w > rhs.w;
	}
};
priority_queue<Node> Q;

int fa[maxn];
int find(int u) {
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	if (n == 1) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j <= n; ++j)
			scanf("%d", &e[i][j]);
		for (int j = 1; j <= n; ++j)
			pos[i][j] = j;
		sort(pos[i] + 1, pos[i] + n + 1, [&](const int &x, const int &y) {
			return e[i][x] < e[i][y];
		});
		e[i][0] += e[i][pos[i][1]];
		Q.emplace(i, 2, (LL)e[i][0] + e[i][pos[i][2]]);
	}
//	for (int i = 1; i <= k; ++i)
//		fprintf(stderr, "%d%c", pos[i][1], " \n"[i == k]);
	sort(E + 1, E + m + 1);
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	LL ans = 0;
	for (int i = 1; i <= m; ) {
		if (!Q.empty() && Q.top().w < (LL)E[i].w) {
//			fprintf(stderr, "1");
			int x = Q.top().x, y = Q.top().y;
			LL w = Q.top().w;
			Q.pop();
//			assert(x >= 1 && x <= k && y >= 1 && y <= n);
			int u = find(pos[x][1]), v = find(pos[x][y]);
			if (u != v) {
				fa[v] = u, ans += w;
				vis[x] = true;
				++cnt[x];
			}
			if (y < n)
				Q.emplace(x, y + 1, (LL)(vis[x] ? 0 : e[x][0]) + e[x][pos[x][y + 1]]);
		}
		else {
//			fprintf(stderr, "2");
			int u = find(E[i].u), v = find(E[i].v);
			if (u != v) fa[v] = u, ans += E[i].w;
			++i;
		}
	}
//	fprintf(stderr, "\n");
//	for (int i = 1; i <= k; ++i)
//		fprintf(stderr, "%d%c", cnt[i], " \n"[i == k]);
	printf("%lld\n", ans);
	return 0;
}
