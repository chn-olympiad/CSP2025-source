//GZ-S00029 遵义市第十九中学 余学森 
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#define ll unsigned long long
using namespace std;

const int K = 12;
const int N = 1e4 + 10;
const int INF = 0x3f3f3f3f;

struct edge {
	int v, w;
	edge(int a, int b) : v(a), w(b) {}
};

struct node {
	int idx, dis, pre;
	node (int a, int b, int c) : idx(a), dis(b), pre(c) {}
	bool operator > (const node &other) const {
	    return dis > other.dis;
	}
};

bool vis[N];
ll dis[N], ans = 0;
int n, m, k;
int c[K][N];
vector<edge> g[N];

void dijkstra() {
	memset(vis, 0, sizeof vis);
    memset(dis, INF, sizeof dis);
	priority_queue<node, vector<node>, greater<node> > q;
	dis[1] = dis[0] = 0;
	q.push(node(1, 0, 0));
	while (q.size()) {
		node val = q.top();
		q.pop();
		int u = val.idx, pre = val.pre;
		if (vis[u]) continue ;
		vis[u] = 1;
		ans += dis[u] - dis[pre];
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v, w = g[u][i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(node(v, dis[v], u));
			}
		}
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		g[u].push_back(edge(v, w));
		g[v].push_back(edge(u, w));
	}

	for (int i = 1; i <= k; i++) {
		vector<int> free;
		for(int j = 0; j <= n; j++) {
			cin >> c[i][j];
			if (c[i][j] == 0) {
				for (int zyn = 0; zyn < free.size();zyn++) {
					g[free[zyn]].push_back(edge(i,0));
					g[i].push_back(edge(free[zyn],0));
				}
				free.push_back(i);
			}
		}
	}
   
    dijkstra();
    cout << ans;
	return 0;
}
