#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5, M = 1e6 + 5, K = 10 + 5;
int n, m, k;
struct Edge { 
	int u, v; long long w;
	bool operator < (const Edge &T) const { return w < T.w; }
} e[M];

bool vis[N];
int fa[N];
long long allm, mi[N][K], val[K];
int find (int x) { return fa[x] == x ? x : fa[x] = find (fa[x]); }

int main () {

	ios::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		allm = min (allm, e[i].w);
	}
	for (int i = 1; i <= k; ++i) {
		cin >> val[i];
		for (int j = 1; j <= n; ++j) 
			cin >> mi[j][i];
	}
	for (int i = 1; i <= n; ++i) fa[i] = i;
	
	sort (e + 1, e + m + 1);
	int tot = 0; long long ans = 0;
	for (int i = 1; i <= m; ++i) {
		int fu = find (e[i].u), fv = find (e[i].v);
		if (fu == fv) continue;
		
		int miu = e[i].w, mii = 0;
		for (int j = 1; j <= k; ++j) {
			if (!vis[j] && miu > mi[fu][j] + mi[fv][j] + val[j]) {
				miu = mi[fu][j] + mi[fv][j] + val[j];
				mii = j;
			} else if (vis[j] && miu > mi[fu][j] + mi[fv][j]) {
				miu = mi[fu][j] + mi[fv][j];
				mii = j;
			}
		}
		vis[mii] = true;
		fa[fv] = fu;
		for (int j = 1; j <= k; ++j) mi[fu][j] = min (mi[fu][j], mi[fv][j]);
		ans += miu;
		tot++;
		
		if (tot == n - 1) break;
	}
	cout << ans;
	
	return 0;
}
