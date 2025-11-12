#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e4 + 5, M = 1e6 + 5, K = 15;

ll n, m, k;

ll c[K];
ll a[K][N];
ll dis[N], mon[N];

bool vis[N];

vector<vector<pair<ll, ll> > > edg(N);

void dij() {
	priority_queue<pair<ll, ll> > pq;
	pq.push({ 0, 1 });
	
	memset(dis, 0x3f, sizeof(dis));
	vis[1] = true;
	dis[1] = 0;
	
	while (!pq.empty()) {
		auto x = pq.top(); pq.pop();
		ll u = x.second;
		
//		if (vis[u]) continue;
//		vis[u] = true;
		
		for (auto tmp : edg[u]) {
			ll v = tmp.second, w = tmp.first;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({ -dis[v], v });
			}
		}
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += dis[i];
	}
	
	cout << ans << '\n';
}

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> k;
	// 城市数量   道路数量   准备进行城市化改造的乡镇数量
	for (int i = 1; i <= m; i ++) {
		// 表示第 i 条道路连接的两座城市与修复该道路的费用
		ll u, v, w; cin >> u >> v >> w;
		
		edg[u].push_back({ w, v });
		edg[v].push_back({ w, u });
	}

	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		for (int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	
	dij();

	return 0;
}