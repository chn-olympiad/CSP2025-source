#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, k, c[15], b[15];

const int maxn = 1e4 + 15;

vector<pair<int, int> > a[maxn];

bool vis[maxn];

priority_queue<pair<int, int> ,vector<pair<int, int> > ,greater<pair<int, int> > > q;

void read() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}
	for (int i = n + 1; i <= n + k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			int w;
			cin >> w;
			a[i].push_back({j, w});
			a[j].push_back({i, w});
		}
	}
}

int calc() {
	memset(vis, 0, sizeof vis);
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		if (b[i]) {
			ans += c[n + i];
		}
	}
	q.push({0, 1});
	while(!q.empty()) {
		pair<int, int> it = q.top();
		q.pop();
		vis[it.second] = true;
		for (int i = 0; i < a[it.second].size(); i++) {
			pair<int, int> x = a[it.second][i];
			if (vis[x.first]) {
				continue;
			}
			if (x.first > n && !b[x.first - n]) {
				continue;
			}
			q.push({it.first + x.second, x.first});
			ans += x.second;
		}
	}
	return ans;
}

int dfs(int x) {
	if (x > k) {
		return calc();
	}
	int minn = dfs(x + 1);
	b[x] = 1;
	minn = min(minn, dfs(x + 1));
	b[x] = 0;
	return minn;
}

void solve() {
	read();
	cout << dfs(1);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

