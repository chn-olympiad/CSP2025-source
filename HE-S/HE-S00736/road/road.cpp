#include <bits/stdc++.h>

using namespace std;

namespace michaele {

	#define rep(i, s, t) for (int i = s; i <= t; i ++)
	typedef long long ll;

	int n, m, K;

	namespace sub1 {

		const int N = 1e4 + 10, M = 1e6 + 10;

		int fa[N];

		struct Edge {
			int x, y, z;
		} e[M];

		int fin (int x) {
			return x == fa[x] ? x : fa[x] = fin (fa[x]);
		}
/*

4 5 0
1 4 6
2 3 7
4 2 5
4 3 4
3 4 6

*/
		void sol () {
			rep (i, 1, n) fa[i] = i;
			rep (i, 1, m) {
				cin >> e[i].x >> e[i].y >> e[i].z;
			}
			sort (e + 1, e + 1 + m, [](Edge a, Edge b) { return a.z < b.z; });
			ll ans = 0;
			rep (i, 1, m) {
				int x = fin (e[i].x), y = fin (e[i].y);
				if (x == y) continue;
				ans += e[i].z;
				fa[x] = y;
			}
			cout << ans << '\n';
		}
	}


	namespace sub2 {

		const int N = 1e3 + 10;

		int fa[N];
		ll dis[N][N], a[N][N], c[N];
		struct Edge { ll x, y, z; } e[N * N];

		int fin (int x) {
			return x == fa[x] ? x : fa[x] = fin (fa[x]);
		}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/
		void sol () {

			rep (i, 1, n) fa[i] = i;
			memset (dis, 0x3f, sizeof dis);
			rep (i, 1, m) {
				ll x, y, z;
				cin >> x >> y >> z;
				if (x > y) swap (x, y);
				dis[y][x] = dis[x][y] = min (dis[x][y], z);
			}
			rep (i, 1, K) {
				cin >> c[i];
				rep (j, 1, n) {
					cin >> a[i][j];
				}
			}
			
			rep (i, 1, K) {
				rep (j, 1, n) {
					rep (k, j + 1, n) {
						dis[k][j] = dis[j][k] = min (dis[j][k], c[i] + a[i][j] + a[i][k]);
					}
				}
			}

			int tot = 0;
			rep (i, 1, n) rep (j, 1, n) {
				e[ ++ tot] = {i, j, dis[i][j]};
			}
			sort (e + 1, e + 1 + tot, [](Edge a, Edge b) {return a.z < b.z;});
			ll ans = 0;
			rep (i, 1, tot) {
				int x = fin (e[i].x), y = fin (e[i].y);
				if (x == y) continue;
				ans += e[i].z;
				fa[x] = y;
			}
			cout << ans << '\n';
		}
	}

	void solve () {
		cin >> n >> m >> K;
		if (K == 0) sub1 :: sol ();
		else sub2 :: sol ();

	}
}

int main () {
	// freopen ("Bf/road3.in", "r", stdin);
	// freopen ("Bf/test.out", "w", stdout);

	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	
	ios :: sync_with_stdio (0);
	cin.tie (0);

	michaele :: solve ();
	

	return 0;
}