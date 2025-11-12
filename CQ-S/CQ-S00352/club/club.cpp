#include<bits/stdc++.h>
using namespace std;
#define int long long
#define il inline
#define rg register
#define vi std::vector<int>
#define L(i, a, b) for (rg int i = (a); i <= (b); i++)
#define R(i, a, b) for (rg int i = (a); i >= (b); i--)
#define rep(i, a) for (rg auto i : (a))
const int N = 1e5 + 5, M = 21, p = 1e9 + 7, inf = 8e18;
int n, a[N][3];
namespace S55{
	constexpr int N = 2e2 + 3;
	int f[N][N][N];
	il void slv(){
		memset(f, -0x3f, sizeof(f)); f[0][0][0] = 0;
		L(i, 0, n - 1){
			L(j, 0, i){
				L(k, 0, i){
					f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k] + a[i + 1][2]);
					f[i + 1][j][k + 1] = max(f[i + 1][j][k + 1], f[i][j][k] + a[i + 1][1]);
					f[i + 1][j + 1][k] = max(f[i + 1][j + 1][k], f[i][j][k] + a[i + 1][0]);
				}
			}
		}
		int ans = -inf / 2;
		L(j, 0, n / 2) L(k, 0, n / 2) if (n - j - k <= n / 2) ans = max(ans, f[n][j][k]);
		std::cout << ans << "\n"; 
	}
}
namespace zrh{
	int vis[N], cnt[N];
	struct node{
		int id, c, i;
		il bool operator < (node x) const{
			return c > x.c;
		}
	};
	priority_queue<node> pq;
	il void slv(){ int t = 1; std::cin >> t; while(t--){
		std::cin >> n; L(i, 1, n) L(j, 0, 2) std::cin >> a[i][j];
		if (n <= 200) S55::slv();
		else{
			int ans = 0; L(i, 1, n) vis[i] = -1; L(i, 0, 2) cnt[i] = 0;
			L(i, 1, n){
				int x = max({a[i][0], a[i][1], a[i][2]}), p = -1;
				L(j, 0, 2) if (a[i][j] == x){ p = j; break; }
				cnt[p]++, vis[i] = p, ans += a[i][p];
			} int fl = -1;
			L(i, 0, 2) if (cnt[i] > n / 2) fl = i;
			if (fl == -1){ std::cout << ans << "\n"; continue; }
			L(i, 1, n){
				if (vis[i] == fl){
					int c1 = -1, c2 = -1, p1 = -1, p2 = -1;
					L(j, 0, 2) if (j != fl && c1 == -1) c1 = a[i][fl] - a[i][j], p1 = j; else if (j != fl) c2 = a[i][fl] - a[i][j], p2 = j; 
					if (c1 > c2) pq.push({i, c2, p2}); else pq.push({i, c1, p1});
				}
			}
			while(pq.size()){
				int id = pq.top().id, c = pq.top().c, i = pq.top().i; pq.pop();
				assert(fl != i);
				cnt[fl]--, ans -= c, cnt[i]++, vis[i] = id; if (cnt[fl] <= n / 2) break;
			}
			L(i, 0, 2) assert(cnt[i] <= n / 2);
			std::cout << ans << "\n"; while(pq.size()) pq.pop();
		}
	}
	}
} signed main(){
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	return zrh::slv(), 0;
}
