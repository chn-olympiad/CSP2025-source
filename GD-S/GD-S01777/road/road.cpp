#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define mems(x, v) memset((x), (v), sizeof (x))
#define mcpy(x, y) memcpy((x), (y), sizeof (x))
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

const int N = 1e4 + 1145;
struct EE {int u, v, w;} edg[1000005]; vector <EE> mst, nE, qwq[N], temp;
namespace U {
	int fa[N]; void init(int n) {for (int i = 1; i <= n; i++) fa[i] = i;}
	int get(int x) {return x == fa[x] ? x : fa[x] = get(fa[x]);}
	inline void merge(int u, int v) {u = get(u), v = get(v); if (u != v) fa[u] = v;}
}
int cost[15], A[15][N];
#include<ctime>
int main() {
	// freopen("D://csps//down//road//road4.in", "r", stdin);
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	// double st = clock();
	// int n = 1e4, m = 1e6, k = 10; U::init(n);
	// for (int i = 1; i <= m; i++) {edg[i].u = rand() % n + 1; do edg[i].v = rand() % n + 1; while (edg[i].u == edg[i].v); edg[i].w = rand() % 1000000000 + 1;}
	// for (int i = 1; i <= k; i++) {cost[i] = 0; for (int j = 2; j <= n; j++) A[i][j] = rand() % 1000000000 + 1;}
	int n, m, k; cin >> n >> m >> k; U::init(n);
	for (int i = 1; i <= m; i++) cin >> edg[i].u >> edg[i].v >> edg[i].w;
	for (int i = 1; i <= k; i++) {cin >> cost[i]; for (int j = 1; j <= n; j++) cin >> A[i][j];}

	sort(edg + 1, edg + m + 1, [](EE x, EE y) {return x.w < y.w;});
	for (int i = 1; i <= m; i++) {
		auto [u, v, w] = edg[i]; if (U::get(u) != U::get(v)) mst.push_back(edg[i]), U::merge(u, v);
	}
	ll ans = 9e18;
	for (int i = 1; i <= k; i++) {
		for (int x = 1; x <= n; x++) qwq[i].push_back({n + i, x, A[i][x]});
		sort(qwq[i].begin(), qwq[i].end(), [](EE x, EE y) {return x.w < y.w;});
	}
	for (int S = 0; S < (1 << k); S++) {
		ll tot = 0; nE = mst; int ec = n - 1; U::init(n + k);
		for (int i = 1; i <= k; i++) if (S >> (i - 1) & 1) {
			ec++; tot += cost[i]; temp.clear();
			//Merge Sorted Array
			int u = 0, v = 0, su = nE.size(), sv = qwq[i].size();
			while (u < su && v < sv) temp.push_back(nE[u].w < qwq[i][v].w ? nE[u++] : qwq[i][v++]);
			while (u < su) temp.push_back(nE[u++]); while (v < sv) temp.push_back(qwq[i][v++]);
			swap(nE, temp);
		}
		for (auto [u, v, w] : nE) if (U::get(u) != U::get(v)) {U::merge(u, v), tot += w; if (!--ec) break;}
		ans = min(ans, tot);
	}
	cout << ans;
	// cerr<<'\n'<<(clock()-st)/CLOCKS_PER_SEC;
	return 0;
}