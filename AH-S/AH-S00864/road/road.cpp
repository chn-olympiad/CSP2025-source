#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, m, k;
long long ans, minans = 1e18;
int c[15], flg[15];
int dis[10025], vis[10025];
vector<pii> e[10025];
priority_queue<pii, vector<pii>, greater<pii> > q;

void prim(int state) {
	memset(flg, 0, sizeof(flg));
	for(int i = 1; i <= k; i++)
		if(state & (1 << (i - 1))) flg[i] = 1;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	while(!q.empty()) q.pop();
	dis[1] = 0; q.push({0, 1});
	while(!q.empty()) {
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1; ans += dis[u];
		for(auto _ : e[u]) {
			int v = _.first, w = _.second;
			if(!(v <= n || flg[v - n])) continue;
			if(w < dis[v]) {
				dis[v] = w;
				q.push({dis[v], v});
			}
		}
	}
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	long long csum = 0;
	for(int i = 1; i <= k; i++) {
		cin >> c[i]; csum += c[i];
		for(int j = 1, w; j <= n; j++) {
			cin >> w;
			e[n + i].push_back({j, w});
			e[j].push_back({n + i, w});
		}
	}
	if(csum == 0) {
		ans = 0;
		prim((1 << k) - 1);
		cout << ans << endl;
		return 0;
	}
	for(int i = 0; i < (1 << k); i++) {
		ans = 0;
		for(int j = 1; j <= k; j++) 
			if(i & (1 << (j - 1))) ans += c[j];
		prim(i);
		minans = min(minans, ans);
	}
	cout << minans << endl;
	return 0;
}
/*
 * I hate you, CCF
 * AFO */
