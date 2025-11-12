#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e4 + 20, maxm = 1e6 + 20, maxk = 13;
struct Edge {
	ll u, v, w;
} e[maxm << 1];
struct Node {
	ll val;
	ll c[maxn];
} C[maxk];
bool cmp(Edge& a,Edge& b) {
	return a.w < b.w;
}
ll fa[maxn];
ll n, m, N, k, ans;
ll find(ll u) {
	if(u == fa[u]) {
		return fa[u];
	}
	return fa[u] = find(fa[u]);
}
void merge(ll u,ll v) {
	ll a = find(u);
	ll b = find(v);
	if(a != b) {
		fa[a] = b;
	}
}
void kruscal() {
	ll cnt = 0;
	sort(e + 1, e + m + 1, cmp);
	for (ll i = 1; i <= m; ++i) {
		if(find(e[i].u) != find(e[i].v)) {
			merge(e[i].u, e[i].v);
			cnt++;
			ans += e[i].w;
		}
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	N = n;
	for (ll i = 1; i <= n + k + 1; ++i) {
		fa[i] = i;
	}
	for (ll i = 1; i <= m; ++i) {
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	}
	for (ll i = 1; i <= k; ++i) {
		scanf("%lld", &C[i].val);
		for (ll j = 1; j <= n; ++j) {
			scanf("%lld", &C[i].c[j]);
		}
		if(C[i].val == 0) {
			N += 1;
			for (ll j = 1; j <= n; ++j) {
				m += 1;
				e[m].u = N;
				e[m].v = j;
				e[m].w = C[i].c[j];
			}
		}
	}
	kruscal();
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
