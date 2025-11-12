#include <bits/stdc++.h>
using namespace std;
// road
int n, m, k;
using ll = long long;
const int N = 1e4 + 25;
const int P = 11;
int c[P];
#define pii pair<ll, int>
#define len first
#define id second
bool used[N], done[N];
vector <pii> e[N];
ll ans, dis[N];
void prim(int ST) {
	priority_queue <pii, vector <pii>, greater <pii> > q;
	q.push({0, 1});
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	for (int i = 1; i <= n + k; i ++ ) done[i] = used[i] = 0;
	ans = 0;
	for (int i = 1; i <= k; i ++ )
		if ((ST >> (i - 1)) & 1) ans += c[i];
	while (q.size()) {
		pii st = q.top();
		q.pop();
		int u = st.id; ll d = st.len;
		if (done[u]) continue;
		ans += d;
		done[u] = 1;
		for (auto edge : e[u]) {
			int v = edge.id; ll w = edge.len;
			if (done[v]) continue;
			if (v > n) {
				int tp = v - n - 1;
				if (!((ST >> tp) & 1)) continue;
			}
			if (u > n && !used[u]) w += c[u - n];
			if (dis[v] > w) {
				dis[v] = w;
				q.push({w, v});
				used[u] = 1;
			}
		}
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++ ) {
		int u, v, w; cin >> u >> v >> w;
		e[u].push_back({w, v});
		e[v].push_back({w, u});
	}
	if (k == 0) {
		prim(0);
		cout << ans << '\n';
		return 0;
	}
	bool flg = 0;
	for (int i = 1; i <= k; i ++ ) {
		int u = i + n;
		cin >> c[i];
		flg |= (c[i] > 0);
		for (int j = 1; j <= n; j ++ ) {
			int tp; cin >> tp;
			e[u].push_back({tp, j});
			e[j].push_back({tp, u});
		}
	}
	if (!flg) {
		prim((1 << k) - 1);
		cout << ans << '\n'; 
		return 0;
	}
	ll ret = 0x3f3f3f3f3f3f3f3f;
	for (int i = 0; i < (1 << k); i ++ ) {
		prim(i);
		ret = min(ret, ans);
	} 
	cout << ret << '\n';
	return 0;
}
