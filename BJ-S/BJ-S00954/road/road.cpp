#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
using LL = long long;
const int N = 10015;
const int M = 10;
int n, m, k;
std::vector<std::pair<int, int> > g[N];
int c[10], a[10][N];
struct edge {
	int u, v, w;
} p[N];
int pcnt;
struct node {
	int u, x, len;
	bool operator < (const node &o) const {
		return len > o.len;
	}
};
bool vis[N];
LL prim(int mask, bool flag = false) {
	LL ans = 0;
	std::priority_queue<node> q;
	memset(vis, false, sizeof(vis));
	q.push({1, 1, 0});
	while (!q.empty()) {
		int u = q.top().u;
		int x = q.top().x;
		int len = q.top().len;
		q.pop();
		if (vis[x])
			continue;
		vis[x] = true;
		ans += len;
		if (flag)
			p[++pcnt] = {u, x, len};
		for (int i = 0; i < g[x].size(); ++i) {
			int v = g[x][i].first;
			int w = g[x][i].second;
			if (v > n && !((mask >> (v - n - 1)) & 1))
				continue;
			if (vis[v])
				continue;
			q.push({x, v, w});
		}
	}
	return ans;
}
void work1() {
	for (int i = 0; i < k; ++i) {
		int u = -1;
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] == 0) {
				u = j;
				break;
			}
		}
		for (int j = 1; j <= n; ++j) {
			if (j != u) {
				g[u].push_back({j, a[i][j]});
				g[j].push_back({u, a[i][j]});
			}
		}
	}
	printf("%lld\n", prim(0));
}
void work2() {
	prim(0, true);
	for (int i = 1; i <= n; ++i)
		g[i].clear();
	for (int i = 1; i <= pcnt; ++i) {
		g[p[i].u].push_back({p[i].v, p[i].w});
		g[p[i].v].push_back({p[i].u, p[i].w});
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 1; j <= n; ++j) {
			g[i + n + 1].push_back({j, a[i][j]});
			g[j].push_back({i + n + 1, a[i][j]});
		}
	}
	LL ans = 9e18;
	for (int s = 0; s < (1 << k); ++s) {
	//	printf("%.2f\n", s * 100. / (1 << k));
		LL sum = 0;
		for (int i = 0; i < k; ++i) {
			if ((s >> i) & 1)
				sum += c[i];
		}
		sum += prim(s);
		ans = std::min(ans, sum);
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	bool flag = true;
	for (int i = 0; i < k; ++i) {
		scanf("%d", &c[i]);
		if (c[i] != 0)
			flag = false;
		bool have = false;
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0)
				have = true;
		}
		if (!have)
			flag = false;
	}
	if (flag)
		work1();
	else
		work2();
	return 0;
}