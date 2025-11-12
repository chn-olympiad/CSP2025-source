#include <bits/stdc++.h>

#define ll long long

#define pii pair <int, ll>
#define mp make_pair

#define eb emplace_back

using namespace std;

const ll INF = 1e18;
const ll N = 1e4 + 20;

vector <pii> g[N];

ll n, m, k;

ll ans, c[11], a[11][N], dis[N], pre[N], cnt[11];

bool vis[N], tag[11];

int main () {
	freopen ("road.in", "r", stdin), freopen ("road.out", "w", stdout);
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);

	cin >> n >> m >> k;
	for (int i = 1, u, v, c; i <= m; i++) cin >> u >> v >> c, g[u].eb (mp (v, c)), g[v].eb (mp (u, c));
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}

	for (int i = 1; i <= n + k; i++) dis[i] = INF;

	priority_queue <pii> q;
	q.push (mp (0, 1)), dis[1] = 0;

	while (!q.empty ()) {
		int u = q.top ().second;
		q.pop ();
		if (vis[u]) continue;
		vis[u] = 1, ans += dis[u];

		if (u <= n) {
			#define v i.first
			#define w i.second

			for (pii i : g[u])
				if (!vis[v] and dis[v] > w)
					dis[v] = w, pre[v] = 0, q.push (mp (-dis[v], v));
				
			#undef v
			#undef w
			
			for (int v = 1; v <= k; v++)
				if (!vis[v + n] and dis[v + n] > a[v][u] + c[v])
					dis[v + n] = a[v][u] + c[v], pre[v + n] = u, q.push (mp (-dis[v + n], v + n));
		} else {
			u -= n;
			for (int v = 1; v <= n; v++)
				if (!vis[v] and dis[v] > a[u][v])
					dis[v] = a[u][v], pre[v] = u, q.push (mp (-dis[v], v)); 	
		}
	}
	
	for (int i = 1; i <= n; i++)
		cnt[pre[i]]++;
	
	for (int i = 1; i <= k; i++)
		if (!cnt[i]) ans -= (c[i] + a[i][pre[i + n]]);

	cout << ans << endl;

	return 0;
}
