#include<bits/stdc++.h>
using namespace std; 
#define endl '\n'
#define LL long long
#define fer(i, a, b, args...) for(int i = (a), ##args; i <= (b); i ++)
#define fel(i, a, b, args...) for(int i = (a), ##args; i >= (b); i --)
template <typename T> void chmin(T &x, T y) { if(y < x) x = y; }
template <typename T> void chmax(T &x, T y) { if(y > x) x = y; }
#define fi first
#define se second 
constexpr int N = 2e4 + 10; 
constexpr int M = 1e6 + 10; 
int n, m, k; 
struct edge {
	int x, y, v; 
	bool operator < (const edge &a) const {
		return v < a.v; 
	}
} a[M]; 
int c[15][N]; 
int fa[N]; 
int found(int x) {
	if(x == fa[x]) return x; 
	return fa[x] = found(fa[x]); 
}
bool merge(int x, int y) {
	x = found(x); y = found(y); 
	if(x == y) return 0; 
	fa[x] = y; 
	return 1; 
}
vector <edge> g[2]; 
LL ans = LONG_LONG_MAX; 
signed main() {
	// freopen("road4.in", "r", stdin); 
	freopen("road.in", "r", stdin); 
	freopen("road.out", "w", stdout); 
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0); 
	cin >> n >> m >> k; 
	fer(i, 1, m) {
		cin >> a[i].x >> a[i].y >> a[i].v; 
	}
	sort(a + 1, a + m + 1); 
	fer(i, 1, n) fa[i] = i; 
	LL sum = 0; 
	fer(i, 1, m) {
		if(merge(a[i].x, a[i].y)) {
			g[0].push_back(a[i]); 
			sum += a[i].v; 
		}
	}
	fer(i, 1, k) {
		fer(j, 0, n) {
			cin >> c[i][j]; 
		}
	}
	chmin(ans, sum); 
	fer(x, 0, (1 << k) - 1) {
		sum = 0; 
		g[1].clear(); 
		fer(i, 1, k) {
			if((x >> i) & 1) {
				sum += c[i][0]; 
				fer(j, 1, n) {
					g[1].push_back({i + n, j, c[i][j]}); 
				}
			}
		}
		fer(i, 1, n + k) fa[i] = i; 
		sort(g[1].begin(), g[1].end()); 
		edge t; 
		for(int i = 0, j = 0; i < g[0].size() || j < g[1].size(); ) {
			if(i == g[0].size()) t = g[1][j ++]; 
			else if(j == g[1].size()) t = g[0][i ++]; 
			else if(g[0][i].v < g[1][j].v) t = g[0][i ++]; 
			else t = g[1][j ++]; 
			if(merge(t.x, t.y)) {
				sum += t.v; 
			}
		}
		chmin(ans, sum); 
	}
	cout << ans << endl; 
	return 0; 
}