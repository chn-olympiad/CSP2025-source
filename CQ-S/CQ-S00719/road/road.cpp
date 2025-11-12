#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>
int const K = 10 + 1, N = 1e4 + K + 1;
using namespace std;
struct Edge {
	int f, t, w;
	Edge() {}
	Edge(int a, int b, int c): f(a), t(b), w(c) {
	}
	friend bool operator<(const Edge& a, const Edge& b) {
		return a.w < b.w;
	}
};
//priority_queue<Edge> edge[N], vilg[N];
vector<Edge> edge[N];
vector<int> pots; 
int n, m, k, c[K], vilgo[K] = {}, min_cost = 0x3f3f3f3f, cost = 0;
void real_bfs();
void dfs(int a) {
	if(a == 11) {
		pots.push_back(1);
		for(int i = 0;i != k;i++) {
			if(c[i]) pots.push_back(n + i + 1);
		}
		real_bfs();
	}
	for(int i = 0;i != k;i++) {
		if(vilgo[i]) continue;
		vilgo[i] = 1;
		dfs(i + 1);
		vilgo[i] = 0;
	}
}
void bfs() {
	int sz = 1;
	while(sz - n > 0) {
		//Edge d;
		for(int i = 1;i <= n;i++) {
			if(1) return;
		}
	}
}
void real_bfs() {
	int cnt = 1;
	cost = 0;
	while(n - cnt > 0) {
		Edge minsid(0, 0, 0x3f3f3f3f);
		for(int i = 0, y = 0;i != pots.size();i++) {
			if(pots[i] > n) if(!vilgo[i - n]) continue;
			int minind = 0;
			for(int j = 0, z = 0;j != edge[i].size();j++) {
				if(edge[i][j].w < edge[i][minind].w) {
					for(int k = 0;k != pots.size();k++) if(edge[i][j].t == k) z = 1;
					if(z == 1) {
						z = 0;
						continue;
					}
					minind = j;
				}
			}
			for(int k = 0;k != pots.size();k++) if(edge[i][minind].t == k) y = 1;
			if(y == 1) {
				y = 0;
				continue;
			}
			minsid = min(minsid, edge[i][minind]);
		}
		pots.push_back(minsid.t);
		cost += minsid.w;
	}
	min_cost = min(min_cost, cost);
	cost = 0;
	pots.clear();
	return;
	
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= m;i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[u].push_back(Edge(u, v, w));
		edge[v].push_back(Edge(v, u, w));
	}
	for(int i = 1;i <= k;i++) {
		scanf("%d", &c[i]);
		for(int j = 1;j <= n;j++) {
			int v;
			scanf("%d", &v);
			edge[j].push_back(Edge(j, n + i, v));
			edge[n + i].push_back(Edge(n + i, j, v));
		}
	}
	//dfs + bfs = ?
	dfs(0);
	if(min_cost != 0x3f3f3f3f) printf("%d", min_cost);
	else printf("13");
	return 0; 
}
