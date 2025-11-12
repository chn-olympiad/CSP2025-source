#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;

const int N = 1e4 + 5, M = 1e6 + 5, K = 15;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;

int n, m, k, tot;
ll a[K][N], c[K], fa[N];
struct edge{
	int u, v; ll w;
}e[M], ne[M], tmp[M];

bool cmp(edge x, edge y){
	return x.w < y.w;
}

int find(int x){
	return (fa[x] == x ? fa[x] : fa[x] = find(fa[x]));
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	ll ans = 0;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++){
		int u = find(e[i].u), v = find(e[i].v), w = e[i].w;
		if (u == v) continue;
		fa[u] = v, ans += w;
		tmp[++tot] = {e[i].u, e[i].v, w};
	}
	for (int i = 1; i < (1 << k); i++){
		ll res = 0; tot = n - 1;
		for (int j = 1; j <= tot; j++) ne[j] = tmp[j];
		for (int j = 1; j <= k; j++){
			if ((i >> (j - 1)) & 1){
				res += c[j];
				for (int p = 1; p <= n; p++) ne[++tot] = {j + n, p, a[j][p]};
			} 
		}
		sort(ne + 1, ne + tot + 1, cmp);
		for (int j = 1; j <= n + k; j++) fa[j] = j;
		for (int j = 1; j <= tot; j++){
			int u = find(ne[j].u), v = find(ne[j].v), w = ne[j].w;
			if (u == v) continue;
			fa[u] = v, res += w;
		}
		ans = min(ans, res);
	}
	cout << ans;
	return 0;
}
