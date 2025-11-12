#include <bits/stdc++.h>
#define PII pair <int, int>
#define pb push_back
#define eb emplace_back

using namespace std;
using ll = long long;

constexpr int N = 1e4 + 5, M = 15, inf = 0x3f3f3f3f;

int n, m, k, C[M], dist[N + M], Dantle[N + M], d[N + M];
vector <PII> e[N + M];

void Prim () {
	memset (dist, 0x3f, sizeof dist); dist[1] = 0;
	
	for (auto v: e[1]) dist[v.first] = min (dist[v.first], v.second);
	
	ll ans = 0;
	for (int i = 1; i <= n + k; i ++ ) {
		int mn = inf, j = 0;
		for (int l = 1; l <= n + k; l ++ ) if (dist[l] && dist[l] + (l > n ? C[l - n] : 0) < mn) j = l, mn = dist[l] + (l > n ? C[l - n] : 0);
		
		if (!j) break;
		
		int x = inf;
		for (auto v: e[j]) if (dist[j] == v.second) x = min (x, v.first);
		d[x] ++ ;
		
		dist[j] = 0, ans += mn, Dantle[j] = mn;
		
		for (auto v: e[j]) dist[v.first] = min (dist[v.first], v.second);
	}
	
//	for (int i = 1; i <= n + k; i ++ ) cout << d[i] << " \n"[i == n + k];
	for (int i = n + 1; i <= n + k; i ++ ) if (d[i] < 1) ans -= Dantle[i];
	
	cout << ans << '\n'; 
}

void solve () {
	cin >> n >> m >> k;
	
	while (m -- ) {
		int u, v, w; cin >> u >> v >> w;
		e[u].eb (v, w), e[v].eb (u, w);
	}
	
	for (int i = 1; i <= k; i ++ ) {
		cin >> C[i];
		for (int j = 1, w; j <= n; j ++ ) cin >> w, e[i + n].eb (j, w), e[j].eb (i + n, w);
	}
	
	Prim ();
}

int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);

	int T = 1;
//	cin >> T;
	while (T -- ) solve ();
	return 0;
}

