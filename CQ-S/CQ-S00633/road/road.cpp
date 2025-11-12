#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, ll>;
const int Mod = 998244353, mod = 1e9 + 7, N = 1e4 + 200, M = 2e6 + 10, K = 22;
vector<pii> g[N];
struct no{
	int u, v;
	ll w;
} mp[M];
int n, m, k, fa[N], fl[K];
ll ans[1 << K], c[K], v[K][N], cnt, minn = 0x3f3f3f3f3f3f3f3f;
bool af = 1;

int fi(int x) {
	return x == fa[x] ? x : fa[x] = fi(fa[x]);
} 

void kr() {
	ans[0] = 0;
	sort(mp + 1, mp + cnt + 1, [&] (no& a, no& b) {
		return a.w < b.w;
	});
	for (int i = 1; i <= n + 10; i++) fa[i] = i;
	for (int i = 1; i <= cnt; i++) {
		int u = mp[i].u, v = mp[i].v;
		int fu = fi(u), fv = fi(v);
		ll w = mp[i].w;
		if (fu != fv) {
			ans[0] += w;
			fa[fu] = fv;
			g[u].push_back({v, w}), g[v].push_back({u, w});
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	memset(ans, 0x3f, sizeof ans);
	for (int i = 1; i <= m; i++) ++cnt, cin >> mp[cnt].u >> mp[cnt].v >> mp[cnt].w;
	if (!k) kr(), cout << ans[0] << endl;
	else {
		for (int i = 1; i <= k; i++) {
			cin >> c[i];
			if (c[i]) af = 0;
			for (int j = 1; j <= n; j++) {
				cin >> v[i][j];
				if (!v[i][j]) fl[i] = j;
			}
			if (!fl[i]) af = 0;
		}
		if (af) {
			for (int i = 1; i <= k; i++) {
				for (int j = 1; j <= n; j++) {
					if (j != fl[i]) mp[++cnt] = {fl[i], j, v[i][j]};
				}
			}
			kr();
			cout << ans[0] << endl;
		} else {
			for (int i = 0; i < (1 << k); i++) {
				int tmep = cnt;
				ll kkk = 0;
				for (int j = 0; j < k; j++) {
					if (i & (1 << j)) {
						kkk += c[j + 1];
						for (int l = 1; l <= n; l++) mp[++cnt] = {n + j + 1, l, v[j + 1][l]};
					}
				}
				kr();
				cnt = tmep;
				minn = min(minn, ans[0] + kkk);
			}
			cout << minn << '\n';
		}
	}
	return 0;
}

