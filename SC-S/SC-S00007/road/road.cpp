#include<bits/stdc++.h>
using namespace std;
int n, m, k, u, v, w, c[15], c1, vis[500005], sum;
vector<pair<int, int>> q[500005];
priority_queue<pair<int, int> > g;
void bfs(int x) {
	for (int i = 0; i < q[x].size(); i++) {
		g.push(make_pair(-q[x][i].second, q[x][i].first));
	}
	vis[x] = 1;
	while (g.size()) {
		int nq = g.top().first;
		int nnq = g.top().second;
		g.pop();
		if (vis[nnq] == 1) {
			continue;
		}
//		cout<<nnq<<' '<<nq<<'\n';
		vis[nnq] = 1;
		sum += nq;
		for (int i = 0; i < q[nnq].size(); i++) {
			g.push(make_pair(-q[nnq][i].second, q[nnq][i].first));
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> u >> v >> w;
		q[u].push_back(make_pair(v, w));
		q[v].push_back(make_pair(u, w));
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> c1;
			q[i].push_back(make_pair(n + i, c1));
			q[n + i].push_back(make_pair(i, c1));
		}
	}
	bfs(1);
	cout << -sum;
	return 0;
}