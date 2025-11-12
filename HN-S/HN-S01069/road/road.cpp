#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 15;
struct node {
	int y, z;
};
int a[M][N], n, m, k;
vector<node> gv[N];
long long ans = LONG_LONG_MAX;
bool vis[N], visp[M];
void dfs(int x, long long sum) {
	if (x == k + 1) {
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
		vis[1] = 1;
		for (node i : gv[1]) {
			q.push({i.z, i.y});
		}
		int qwq = 1;
		while (qwq < n) {
			while (vis[q.top().second]) {
				q.pop();
			}
			pair<int, int> t = q.top();
			q.pop();
			vis[t.second] = 1;
			for (node i : gv[t.second]) {
				if (!vis[i.y]) {
					q.push({i.z, i.y});
				}
			}
			sum += t.first;
			qwq++;
		}
		ans = min(ans, sum);
		return;
	}
	dfs(x + 1, sum);
	for (int i = 1; i <= n; i++) {
		if (x != i) {
			gv[i].push_back({x, a[x][i]});
			gv[x].push_back({i, a[x][i]});
		}
	}
	dfs(x + 1, sum + a[x][0] + a[x][x]);
	for (int i = 1; i <= n; i++) {
		if (x != i) {
			gv[i].pop_back();
			gv[x].pop_back();
		}
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		gv[x].push_back({y, z});
		gv[y].push_back({x, z});
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	dfs(1, 0);
	cout << ans; 
	return 0;
}


