#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair
#define fi first
#define se second
#define db double
#define pii pair < int, int >

const int MAXN = 1e4 + 7, MAXM = 1e6 + 7;
const ll Inf = 1e18 + 7;

int n, m, k;

struct Edge {
	ll u, v, w;
	bool operator < (const Edge other) const {
		return w < other.w;
	}
} E[MAXM];

ll f[MAXN][20], C[20], A[20][MAXN], fa[MAXN];

int Vis[20], Vs[MAXN][20];

int find(int u) { return u == fa[u] ? u : (fa[u] = find(fa[u])); }

ll ans;

void Work() {
	sort(E + 1, E + 1 + m);
	int cnt = 0;
	for (int i = 1; i <= m; i ++) {
		if (cnt >= n - 1) break;
		ll u = E[i].u, v = E[i].v, w = E[i].w;
		int fu = find(u), fv = find(v);
		if (fu == fv) continue;
		ll sum = Inf; int id = 0;
		for (int j = 1; j <= k; j ++) {
			if (Vis[j]) {
				ll kk = f[fu][j] + f[fv][j];
				if (Vs[fu][j]) kk -= f[fu][j];
				if (Vs[fv][j]) kk -= f[fv][j];
				if (sum > kk) id = j, sum = kk;
			} else {
				if (sum > f[fu][j] + f[fv][j] + C[j]) id = j, sum = f[fu][j] + f[fv][j] + C[j];
			}
		}
		if (sum <= w) {
			Vis[id] = 1; Vs[fu][id] = 1, Vs[fv][id] = 1;
			ans += sum;	
		} else ans += w;
		for (int j = 1; j <= k; j ++) {
			if (f[fu][j] > f[fv][j]) Vs[fu][j] = Vs[fv][j]; 
			else if (f[fu][j] == f[fv][j]) Vs[fu][j] = max(Vs[fu][j], Vs[fv][j]);
			f[fu][j] = min(f[fu][j], f[fv][j]);
		}
		fa[fv] = fu;
		cnt ++;
	}
}

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++) fa[i] = i;
	for (int i = 1; i <= m; i ++)
		cin >> E[i].u >> E[i].v >> E[i].w;
	for (int i = 1; i <= k; i ++) {
		cin >> C[i];
		for (int j = 1; j <= n; j ++) {
			cin >> A[i][j];
			f[j][i] = A[i][j];
		}
	}
	Work();
	cout << ans << '\n';
	return 0;
}
/*
傻逼看错题耗了 1h 服了
傻逼题秒了，对于每个点维护 10 个最短距离暴力转移就行 
等会再来。 
听天由命了 
*/
