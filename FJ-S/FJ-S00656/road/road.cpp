#include <bits/stdc++.h>
#define Write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define Na1L0n9 cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int MOD = 998244353;
struct edge {
	ll to, val;
};
ll n, m, k, ans, a[20][N], c[N], dis[N];
vector <edge> G[N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	Write by Na1L0n9
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	priority_queue <ll, vector<ll>, greater<ll> > q;
	q.push(1);
	for (int i = 2; i <= n; i++) {
		dis[i] = 1e18;
	}
	while (!q.empty()) {
		int u = q.top();
		q.pop();
		for (edge v : G[u]) {
			if (dis[u] + v.val < dis[v.to]) {
				dis[v.to] = dis[u] + v.val;
				q.push(v.to);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		ans += dis[i];
	}
	ans /= 2;
	for (int i = 1; i <= k; i++) {
		ll t = c[i];
		for (int j = 1; j <= n; j++) {
			t += a[i][j];
		}
		ans = min(ans, t);
	}
	cout << ans;
	return 0;
}

