#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define ll long long
#define P pair<ll, int>
int n, m, k;
vector<pair<int, ll> > g[20005];
ll dis[20005], c[20005];
bool vis[20005], flag[20005];
inline bool valid(int x) {
	return ((x >= 1 && x <= n) || (flag[x]));
}
ll prim() {
	for (int i = 1; i <= n + k; i++) dis[i] = 0x3f3f3f3f3f3f3f3f, vis[i] = false;
	dis[1] = 0;
	priority_queue<P, vector<P >, greater<P > > q;
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (!valid(u) || vis[u]) continue;
		vis[u] = true;
		for (pair<int, ll> e : g[u]) {
			int v = e.first; ll w = e.second;
			if (valid(v) && !vis[v] && dis[v] > w) {
				dis[v] = w;
				q.push(make_pair(dis[v], v));
			}
		}
	}
	ll res = 0;
	for (int i = 1; i <= n + k; i++)
		if (valid(i)) res += dis[i];
	return res;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			g[n + i].push_back(make_pair(j, x));
			g[j].push_back(make_pair(n + i, x));
		}
	}
	ll ans = prim();
	for (int i = 0; i < (1 << k); i++) {
		ll base = 0;
		for (int j = 1; j <= k; j++) {
			flag[n + j] = ((i >> (j - 1)) & 1);
			if (flag[n + j]) base += c[j];
		}
		ll now = prim() + base;
		//for (int j = 1; j <= k; j++) cout << flag[n + j] << ' ';
		//cout << now << endl;
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}
