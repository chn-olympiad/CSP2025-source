#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e4 + 50 , M = 1e6 + 5000;
int n , m , k , cost[N];
bitset<N> ua;
struct edge {
	int u , v , w;
} e[M];
int fa[N];
int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }
void merge(int x , int y) {
	x = find(x) , y = find(y);
	if (x == y) return;
	fa[x] = y;
}
bool same(int x , int y) {
	return find(x) == find(y);
}
signed main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n >> m >> k;
	int pt = 0;
	for (int i = 1; i <= m; i++) {
		pt++;
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1 , c; i <= k; i++) {
		cin >> cost[i];
		for (int j = 1; j <= n; j++) {
			cin >> c;
			e[++pt] = {j , n + i , c};
		}
	}
	sort(e + 1 , e + pt + 1 , [](const edge &A , const edge &B) {
		return A.w < B.w;
	});
	long long ans = 1e18;
	for (int sta = 0; sta < (1 << k); sta++) {
		// init
		ua.reset();
		for (int i = 1; i <= n + k; i++) fa[i] = i;
		// init
		long long now = 0;
		for (int j = 0; j < n; j++) if (sta >> j & 1) {
			now += cost[j + 1]; ua[j + 1] = 1;
		}
		int need = n + __builtin_popcount(sta) - 1;
		for (int i = 1; need && i <= pt; i++) {
			if (e[i].v > n && !ua[e[i].v - n]) continue;
			if (same(e[i].u , e[i].v)) continue;
			now += e[i].w; merge(e[i].u , e[i].v);
			--need;
		}
//		cerr << "--- " << sta << ' ' << now << '\n';
		ans = min(ans , now);
	}
	cout << ans << '\n';
	return 0;
}
