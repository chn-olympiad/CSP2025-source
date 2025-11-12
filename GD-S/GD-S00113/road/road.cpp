#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, k;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
const int K = 15;
ll c[N];
ll a[K][N];
struct node {
	int v;
	ll w;
};
vector<node> G[N];
int vis[N], cnt;

bool operator< (node x, node y) {
	return x.w > y.w;
}

ll work() {
	ll ans = 0;
	priority_queue<node> q; 
	q.push((node){1, 0});
	while (!q.empty()) {
		node p = q.top();
		q.pop();
		if (vis[p.v]) continue;
		vis[p.v] = 1;
		cnt++;
		ans += p.w;
		if (cnt == n) break;
		for (auto x : G[p.v]) {
			if (vis[x.v]) continue;
			q.push(x);
		}
	}
	return ans;
}

void solve() {
	cin >> n >> m >> k;
	int flag = 1;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back((node){v, w});
		G[v].push_back((node){u, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i]) flag = 0;
		int ff = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (!a[i][j]) ff = 1;
		}
		if (!ff) flag = 0;
	}
	if (flag) {
		for (int i = 1; i <= k; i++) {
			int pos = 0;
			for (int j = 1; j <= n; j++) {
				if (!a[i][j]) {
					pos = j;
					break;
				}
			}
			for (int j = 1; j <= n; j++) {
				if (j == pos) continue;
				G[pos].push_back((node){j, a[i][j]});
				G[j].push_back((node){pos, a[i][j]});
			}
		}
	}
	ll ans = work();
	printf("%lld\n", ans);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
	return 0; 
}
