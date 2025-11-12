#include <bits/stdc++.h>
using namespace std;
long long n, m, k, a[(int)1e4 + 10][10], ans, c[(int)1e4 + 10];
vector<pair<int, int> > g[(int)1e4 + 10];
bool flag, vis[(int)1e4 + 10];
long long dijast() {
	priority_queue<pair<int, long long> > q;
	q.push({1, 0});
	while(!q.empty()) {
		auto u = q.top();
		q.pop();
		int wei = u.first;
		if(vis[wei]) continue;
		vis[wei] = 1;
		long long dist = u.second;
		ans = max(ans, dist);
		for(auto i : g[wei]) {
			if(!vis[i.first]) {
				q.push({i.first, dist + i.second});
			}
		}
	}
	return ans;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	int u, v, w;
	for(int i = 1;i <= m;i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i = 1;i <= k;i ++) {
		cin >> c[i];
		if(c[i] != 0) flag = 1;
		for(int j = 1;j <= n;j ++) {
			cin >> a[j][i];
			if(a[i][j] != 0) flag = 1;
		}
	}
	if(!flag && k) {
		cout << 0;
	} else {
	    cout << dijast();
	}
	return 0;
}
