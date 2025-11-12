// godmoo's code 
#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define ep emplace
#define fi first
#define se second
#define lbd lower_bound
#define ubd upper_bound
#define mathmod(a, m) (((a) % (m) + (m)) % (m))
#define all(a) (a).begin(), (a).end()
typedef long long ll; typedef unsigned long long ull; typedef pair<int, int> pii;

typedef tuple<int, int, int> t3;

const int N = 1e4 + 5, K = 11;
int n, m, k, c[K];
vector<t3> E, _E;

int fa[N + K];
int find(int x){ return x == fa[x] ? x : fa[x] = find(fa[x]); }

#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

int main(){
	file(road);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; i++) cin >> u >> v >> w, E.eb(u, v, w);
	sort(all(E), [](t3 x, t3 y){ return get<2>(x) < get<2>(y); });
	iota(fa + 1, fa + n + 1, 1);
	for(auto e : E){
		int u = get<0>(e), v = get<1>(e);
		if((u = find(u)) != (v = find(v))){
			fa[u] = v, _E.eb(e);
			if((int)_E.size() == n - 1) break;
		}
	} E = _E;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1, w; j <= n; j++) cin >> w, E.eb(n + i, j, w);
	} ll ans = 1e18;
	sort(all(E), [](t3 x, t3 y){ return get<2>(x) < get<2>(y); });
	for(int i = 0; i < 1 << k; i++){
		iota(fa + 1, fa + n + k + 1, 1);
		int cnt = 0, lim = n; ll S = 0;
		for(int j = 0; j < k; j++) if(i >> j & 1) S += c[j + 1], lim++;
		for(auto e : E){
			int u = get<0>(e), v = get<1>(e), w = get<2>(e);
			if(u > n && !(i >> (u - n - 1) & 1)) continue;
			if(v > n && !(i >> (v - n - 1) & 1)) continue;
			if((u = find(u)) != (v = find(v))){
				fa[u] = v, S += w;
				if(++cnt == lim - 1) break;
			}
		}
 		assert(cnt == lim - 1);
		ans = min(ans, S);
	} cout << ans << endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

out:
13

---

Let |E| = nk + m.
O(|E|\log|E| + 2 ^ k \cdot |E|).

Optimization: if edge e isn't on MST of ordinary graph, it shouldn't be on MST of G'. |E|: nk + m -> nk + n. 
Let |E| = nk + n.
O(m\log m + |E|\log|E| + 2 ^ k \cdot |E|).
*/
