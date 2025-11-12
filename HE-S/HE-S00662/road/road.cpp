#include<bits/stdc++.h>
#define up(i,l,r) for(ll i=l,E##i=r;i<=E##i;++i)
#define dn(i,l,r) for(ll i=l,E##i=r;i>=E##i;--i)
using namespace std;
typedef long long ll;
constexpr ll N = 5 + 1e4, M = 5 + 1.2e7, K = 15;

int n, m, k, ans;
ll a[K][N], c[K], f[N];
struct E { int u, v; ll w; } e[M];
vector<E> g[N];

void input() {
	cin >> n >> m >> k;
	up (i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;
	up (j, 1, k) {
		cin >> c[j];
		up (i, 1, n) cin >> a[j][i];
	}
}

int fin(int u) { return f[u] == u ? u : f[u] = fin(f[u]); }
bool cmp(E x, E y) { return x.w < y.w; }

void krustal() {
	int fu, fv;
	up (i, 1, n) f[i] = i;
	sort(e + 1, e + m + 1, cmp);
	up (i, 1, m) {
		int u = e[i].u, v = e[i].v;
		ll w = e[i].w;
		fu = fin(u), fv = fin(v);
		if (fu != fv)  	{
			f[fu] = fv;
			g[u].push_back({u, v, w});
			g[v].push_back({v, u, w});
			ans += w;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	input();
	krustal();
	cout << ans;
	return 0;
}
