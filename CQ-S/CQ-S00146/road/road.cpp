#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100005;
int n, m, k;
ll ans=1e18, mn;
vector<pair<int, int> > g[N];
//vector<pair<int, int> > z[N];

int vis[N];
void dfs(int u, int fa) {
	vis[u] = 1;
	for(int i=0, v; i<(int)g[u].size(); ++i) {
		v = g[u][i].first;
		if(v == fa) continue;
		dfs(v, u);
	}
}

ll dis[N];
void dj(int s) {
	memset(dis, 0x3f, sizeof dis);
	priority_queue<int> q;
	q.push(s);
	dis[s] = 0;
	while(!q.empty()) {
		int u = q.top();
		q.pop();
		for(int i=0, v, w; i<(int)g[u].size(); ++i) {
			v = g[u][i].first;
			w = g[u][i].second;
//			if(v == fa) continue;
			if(dis[v] > dis[u]+w) {
				dis[v] = dis[u]+w;
				q.push(v);
			}
		}
	}
}

void sol1() {
	for(int i=1, u, v, w; i<=m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int j=1; j<=n; j++) {
		dj(j);
		mn = 0;
		for(int i=1; i<=n; i++)
			mn += dis[i];
		ans = ans<mn?ans:mn;
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	if(k == 0) {
		sol1();
		return 0;
	}
	return 0;
}
