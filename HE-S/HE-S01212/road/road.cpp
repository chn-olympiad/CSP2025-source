#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int maxn = 2e6 + 5; 
const int maxm = 1e4 + 5;
struct edge{
	int from, to, opt;
	ll w;
} g[maxn];
ll a[15][maxn];
int fa[maxm << 1];
bool cmp(edge x, edge y) {
	if (x.w == y.w) {
		return a[x.opt][0] < a[y.opt][0];
	}
	return x.w < y.w;
}

int Find(int x) {
	return (x == fa[x] ? x : fa[x] = Find(fa[x]));
}

void coder() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> g[i].from >> g[i].to >> g[i].w;
	}
	int tot = m;
	for (int i = 1; i <= k; ++i) {
		cin >> a[i][0];
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			g[++tot] = {i + n, j, i, a[i][j]};
		}
	}
	sort(g + 1, g + 1 + tot, cmp);
	ll ans = 1e18;
	for (int s = 0; s < (1 << k); ++s) {
		int cnt = 0;
		ll res = 0;
		for (int j = 0; j < k; ++j) {
			if ((s >> j) & 1) {
				res += a[j + 1][0];
				++cnt;
			}
		}
		cnt += n - 1;
		for (int i = 1; i <= n + k; ++i) {
			fa[i] = i;
		}
		int i = 1;
		
		while (cnt) {
			int u = g[i].from;
			int v = g[i].to;
			ll w = g[i].w;
			int opt = g[i].opt;
			++i;
			if (opt == 0 || ((s >> (opt - 1)) & 1)) {
				int x = Find(u);
				int y = Find(v);
				if (x == y) {
					continue;
				} else {
					fa[x] = y;
					res += w;
					--cnt;
				}
			}
		}
		ans = min(ans, res);
	}
	cout << ans;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	coder();
	
	return 0; 
}
