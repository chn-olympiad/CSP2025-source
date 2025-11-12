#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

const int MAXN = 10015, MAXK = 15;
int n, m, k, vis[MAXN], c[MAXK], father[MAXN], siz[MAXN];
long long cnt, dis[MAXN], roads[MAXN][MAXN];
bool is_A = true;
struct Node{
	int v;
	long long w;
};
vector<Node> G[MAXN];

void init() {
	for (int i = 1; i <= n; ++i) {
		father[i] = i;
		siz[i] = 1;
	}
	for (int i = 1; i <= k; ++i) {
		father[n + i] = i;
		siz[n + i] = 0;
	}
}

int Find(int u) {
	if (father[u] == u)return u;
	return father[u] = Find(father[u]);
}

void Union(int lhs, int rhs) {
	if (lhs == rhs)return;
	int rt1 = Find(lhs), rt2 = Find(rhs);
	if (rt1 == rt2)return;
	if (rt1 < rt2) {
		father[rt2] = rt1;
		siz[rt1] += siz[rt2];
	} else {
		father[rt1] = rt2;
		siz[rt2] += siz[rt1];
	}
}

void prim() {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	minHeap.push(make_pair(0, 1));
	while (!minHeap.empty() && siz[1] < n) {
		int u = minHeap.top().second;
		long long d = minHeap.top().first;
		minHeap.pop();
		if (vis[u])continue;
		cnt += dis[u];
		vis[u] = 1;
		Union(u, 1);
		for (int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i].v, w = G[u][i].w;
			if (v > n) {
				w += c[v];
			}
			if (!vis[v] && w < dis[v])
				dis[v] = w;
				minHeap.push(make_pair(dis[v], v));
		}
	}
} 

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back(Node{v, w});
		G[v].push_back(Node{u, w}); 
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		if (c[i] != 0)is_A = false;
		for (int j = 1; j <= n; ++j) {
			cin >> roads[i][j];
		}
	}
	init();
	if (k == 0) {
		prim();
		cout << cnt;
		return 0;
	}
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			G[n + i].push_back(Node{j, roads[i][j]});
			G[j].push_back(Node{n + i, roads[i][j]});
		}
	}
	prim();
	cout << cnt;
	return 0;
}
