#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e4 + 5;

int n, m, k, ans;
int u, v, w;
int c[20], num[20][20];
vector<vector<pair<int, int> > > g[N];

struct Node {
	int x, y;
	bool operator < (const Node a) const {
		return y < a.y;
	}
} node[N];

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if (ch == '-') {
			f = -f;
		}
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
	}
	return x * f;
}

int init(vector<vector<pair<int, int> > > g[N]) {
	int res, dis[N];
	bool vis[N];
	memset(dis, 0x3f, sizeof dis);
	priority_queue<Node> q;
	q.push({1, 0});
	dis[1] = 0;
	while (!q.empty()) {
		int u = q.top().x;
		q.pop();
		if (vis[u] == true) {
			continue;
		}
		vis[u] = true;
		res += dis[u];
		for (pair<int, int> it : g[u]) {
			int v = it.first, w = it.second;
			if (!vis[u] && w < dis[v]) {
				q.push({v, w});
			}
		}
	}
	return res;
}

void dfs(int x, vector<vector<pair<int, int> > > g, int sum) {
	if (x == k + 1) {
		return;
	}
	dfs(x + 1, g, sum);
	vector<vector<pair<int, int> > > G[N];
	for(int i = 1; i <= n; i++) {
		g[n + x].push_back(make_pair(i, num[x][i]));
		g[i].push_back(make_pair(n + x, num[x][i]));
	}
	sum += c[x];
	ans = min(ans, init(G) + sum);
	dfs(x + 1, G, sum);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	// 输入
	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) {
		u = read(), v = read(), w = read();
		// 存储
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	// 排序
	// 存储 + 处理
	for(int i = 1; i <= k; i ++) {
		c[i] = read();
		for(int j = 1; j <= n; j ++) {
			num[i][j] = read();
			g[n + i].push_back(make_pair(j, w));
			g[j].push_back(make_pair(n + i, w));
		}
	}
	int ans = init(g);
	dfs(1, g, 0);
	// 输出
	printf("%d\n", ans);
	return 0;
}