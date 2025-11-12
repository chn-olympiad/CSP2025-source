#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define il inline
#define rg register
#define vi std::vector<int>
#define L(i, a, b) for (rg int i = (a); i <= (b); i++)
#define R(i, a, b) for (rg int i = (a); i >= (b); i--)
#define rep(i, a) for (rg auto i : (a))
const int N = 1e4 + 5, M = 1e6 + 5, K = 11, p = 1e9 + 7;
const LL inf = 8e18;
namespace zrh{
	int n, m, k, f[N + K], s[N + K], c[K], w[K][N];
	il int get(int x){ return x == f[x] ? x : f[x] = get(f[x]); }
	il int unite(int x, int y){
		x = get(x), y = get(y);
		if (x == y) return 0;
		if (s[x] > s[y]) std::swap(x, y);
		f[x] = y, s[y] += s[x];
		return 1;
	}
	struct node{
		int u, v, w;
		il bool operator < (node x) const{
			return w < x.w;
		}
	}e[M], tmp[M + N * K];
	vector<pair<int, int> > g[K]; int flA = 1;
	il void bf(){
//		std::cerr << "bf\n";
		LL ans = inf / 2;
		L(st, 0, (1LL << k) - 1){
			LL ret = 0; int cur = m, ppc = 0; L(i, 1, m) tmp[i] = e[i]; L(i, 1, n + k) f[i] = i, s[i] = 1;
			L(i, 1, k) if (st >> (i - 1) & 1){
				ret += c[i], ppc++;
				L(j, 1, n) tmp[++cur] = {i + n, j, w[i][j]}; 
			}
			if (ret >= ans) continue;
//			std::cerr << cur << "\n";
			sort(tmp + 1, tmp + cur + 1); int tot = 0;
			L(i, 1, cur){
				int u = tmp[i].u, v = tmp[i].v, w = tmp[i].w;
				if (get(u) != get(v)){
					unite(u, v), ++tot, ret += (LL)w;
					if (tot == n + ppc - 1) break;
				}
			}
//			std::cerr << ret << "\n";
			ans = min(ans, ret);
		}
		std::cout << ans;
	}
	il void ws1(){
//		std::cerr << "ws1\n";
		LL ans = inf / 2; int B = 8 * (int)sqrt(n), C = max(n, 58 * (int)sqrt(m));
		if (n <= 1000) B = 3 * (int)sqrt(n), C = max(n, 25 * (int)sqrt(m));
		if (B >= n) B = n; if (C >= m) C = m;
		L(st, 0, (1LL << k) - 1){
			LL ret = 0; int cur = C, ppc = 0; L(i, 1, C) tmp[i] = e[i]; L(i, 1, n + k) f[i] = i, s[i] = 1;
			L(i, 1, k) if (st >> (i - 1) & 1){
				ret += c[i], ppc++;
//				L(j, 1, n) tmp[++cur] = {i + n, j, w[i][j]}; 
				L(j, 0, B - 1) tmp[++cur] = {i + n, g[i][j].second, g[i][j].first};
			}
			if (ret >= ans) continue;
//			std::cerr << cur << "\n";
			sort(tmp + 1, tmp + cur + 1); int tot = 0;
			L(i, 1, cur){
				int u = tmp[i].u, v = tmp[i].v, w = tmp[i].w;
				if (get(u) != get(v)){
					unite(u, v), ++tot, ret += (LL)w;
					if (tot == n + ppc - 1) break;
				}
			}
			ans = min(ans, ret);
		}
		std::cout << ans;
	}
	il void ws2(){
//		std::cerr << "ws2\n";
		LL ans = inf / 2; int B = 20 * (int)sqrt(n), C = max(n, 85 * (int)sqrt(m));
		if (n <= 1000) B = 10 * (int)sqrt(n), C = max(n, 45 * (int)sqrt(m));
		if (B >= n) B = n; if (C >= m) C = m;
		L(st, 0, (1LL << k) - 1){
			LL ret = 0; int cur = C, ppc = 0; L(i, 1, C) tmp[i] = e[i]; L(i, 1, n + k) f[i] = i, s[i] = 1;
			L(i, 1, k) if (st >> (i - 1) & 1){
				ret += c[i], ppc++;
//				L(j, 1, n) tmp[++cur] = {i + n, j, w[i][j]}; 
				L(j, 0, B - 1) tmp[++cur] = {i + n, g[i][j].second, g[i][j].first};
			}
			if (ret >= ans) continue;
//			std::cerr << cur << "\n";
			sort(tmp + 1, tmp + cur + 1); int tot = 0;
			L(i, 1, cur){
				int u = tmp[i].u, v = tmp[i].v, w = tmp[i].w;
				if (get(u) != get(v)){
					unite(u, v), ++tot, ret += (LL)w;
					if (tot == n + ppc - 1) break;
				}
			}
			ans = min(ans, ret);
		}
		std::cout << ans;
	}
	il void slv(){
		std::cin >> n >> m >> k; L(i, 1, n + k) f[i] = i, s[i] = 1;
		L(i, 1, m){
			int u, v, w; std::cin >> u >> v >> w;
			e[i] = {u, v, w}, tmp[i] = e[i];
		}
		sort(e + 1, e + m + 1);
		L(i, 1, k){
			std::cin >> c[i]; flA &= (c[i] == 0);
			L(j, 1, n) std::cin >> w[i][j], g[i].push_back({w[i][j], j});
			sort(g[i].begin(), g[i].end());
		}
//		if (n <= 1000 && m <= 100000){ bf(); return ; }
		if (k <= 5){ ws2(); return ;} ws1();
	}
} signed main(){
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	return zrh::slv(), 0;
}
