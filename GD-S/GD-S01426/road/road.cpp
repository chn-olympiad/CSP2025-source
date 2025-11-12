#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000015;
int f[N], n, m, k, c[N];
struct E{ int u, v, w;};
bool operator <(E x, E y){ return x.w < y.w;}
int find(int x){ return f[x] == x? x: f[x] = find(f[x]);}
vector <E> g[1024];
ll mst(vector <E> e1, vector <E> e2, vector <E> &e3){
	int K = e1.size();
	for(auto i: e2) e1.push_back(i);
	inplace_merge(e1.begin(), e1.begin() + K, e1.end());
	iota(f + 1, f + n + k + 1, 1);
	ll ans = 0; e3.clear(); 
	for(auto i: e1) if(find(i.u) != find(i.v)) e3.push_back(i), f[find(i.u)] = find(i.v), ans += i.w;
	return ans;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k; g[0].resize(m);
	for(int i = 0; i < m; i++) cin >> g[0][i].u >> g[0][i].v >> g[0][i].w;
	sort(g[0].begin(), g[0].end());
	ll res = mst(g[0], {(E){1, 1, 0}}, g[0]);
	for(int i = 0; i < k; i++){
		g[1 << i].resize(n); cin >> c[i];
		for(int j = 0; j < n; j++) cin >> g[1 << i][j].w, g[1 << i][j].u = j + 1, g[1 << i][j].v = i + n + 1;
		sort(g[1 << i].begin(), g[1 << i].end());
	}
	for(int i = 1; i < (1 << k); i++){
		ll sm = 0, hb = 0;
		for(int j = 0; j < k; j++) if(i >> j & 1) sm += c[j], hb = 1 << j;
		ll k = mst(g[i ^ hb], g[hb], g[i]);
		res = min(res, sm + k);
	}
	cout << res;
	return 0;
} 
