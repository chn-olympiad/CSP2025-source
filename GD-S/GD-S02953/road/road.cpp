#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e4+5, M = 1e6+5, K = 15;
int n, m, k, f[N], c[K], a[K][N];
struct edge{
	int u, v, w;
	bool operator<(edge x) const{
		return w < x.w;
	}
} e[M];
struct edge2{
	int u, v, w;
	bool operator<(edge2 x) const{
		return w < x.w;
	}
} s[M];
int finds(int x){ return f[x] == x? x: finds(f[x]); }
vector<pair<int, int> > g[K];
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w; cin >> u >> v >> w;
		e[i] = {u, v, w}; 
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			int w; cin >> w;
			g[i].push_back({w, j});
		}
		sort(g[i].begin(), g[i].end());
	}
	sort(e+1, e+1+m);
	for(int i = 1; i <= n; i++) f[i] = i;
	int ans = 0, cnt = 0;
	for(int i = 1; i <= m; i++){
		int fx = finds(e[i].u), fy = finds(e[i].v);
		if(fx != fy){
			f[fx] = fy;
			ans += e[i].w;
			e[++cnt] = {e[i].u, e[i].v, e[i].w};
		}
	}
//	for(int i = 1; i < n; i++) cout << e[i].u << " " << e[i].v << " " << e[i].w << '\n';
	for(int i = (1<<k); i >= 0; i--){
		int nowans = 0, cnt2 = 0, x = __builtin_popcount(i);
		for(int j = 1; j < n; j++) s[++cnt2] = {e[j].u, e[j].v, e[j].w};
		for(int j = 0; j < k; j++) if(i&(1<<j)){
			nowans += c[j+1];
			for(auto x:g[j+1]){
				s[++cnt2] = {j+1+n, x.second, x.first};
			}
		}
		stable_sort(s+1, s+1+cnt2);
		int ecnt = 0;
		for(int j = 1; j <= n+k; j++) f[j] = j;
		for(int j = 1; j <= cnt2; j++){
			int fx = finds(s[j].u), fy = finds(s[j].v);
			if(fx != fy){
				++ecnt;
				f[fx] = fy;
				nowans += s[j].w;
				if(nowans >= ans) break;
				if(ecnt == n+x-1) break;
			}
		}
		ans = min(ans, nowans);
	} cout << ans << '\n';
	return 0;
}
