#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

ll n, m, k, cnt, ans, head[10005], dist[10005];
struct Node {
	ll u, v, w, next = -1;
}edge[1000005];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

void add(ll u, ll v, ll w) {
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void dijkstra(ll start) {
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		ll u = cur.second;
		for (ll i = head[u];i != -1;i = edge[i].next) {
			ll v = edge[i].v, _old = dist[v], _new = dist[u] + edge[i].w;
			if (_new < _old) {
				dist[v] = _new;
				pq.push({ _new, v });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	fill(head, head + 100005, -1);
	fill(dist, dist + 100005, 1e18);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (ll i = 1, u, v, w;i <= m;i++) {
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1, c;i <= k;i++) {
		cin >> c;
		for (int j = 1, a;j <= n;j++) cin >> a;
	}
	dijkstra(1);
	for (int i = 1;i <= n;i++) ans += dist[i];
	cout << ans << "\n";
	return 0;
}
