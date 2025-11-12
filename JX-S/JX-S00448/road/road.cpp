#include <bits/stdc++.h>
#define int long long
#define PII pair <int, int>
#define N 500005
#define M 2500005
const int INF = 1e18;
using namespace std;

int fa[N];
int fnd(int u){
	return u == fa[u] ? u : fa[u] = fnd(fa[u]);
}

int n, m, k;
struct edge{
	int u, v, w;
	bool operator < (const edge &oth) const{
		return w < oth.w;
	}
}e[M];
int tot;

int c[15], a[15][N];

void solve(){
	cin >> n >> m >> k;
	
	for(int i = 1; i <= m; i++){
		int u, v, w; cin >> u >> v >> w;
		e[++tot] = {u, v, w};
	}
	
	bool flg = 1;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		flg &= (c[i] == 0);
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	
	if(flg){
		for(int i = 1; i <= n + k; i++)
			fa[i] = i;
			
		int ans = 0, sum = n;
		
		for(int i = 1; i <= k; i++){
			int p = 0;
			for(int j = 1; j <= n; j++)
				if(a[i][j] == 0) p = j;
			for(int j = 1; j <= n; j++)
				e[++tot] = {p, j, a[i][j]};
		}
		
		sort(e + 1, e + 1 + tot);
		for(int i = 1; i <= tot; i++){
			int u = e[i].u, v = e[i].v, w = e[i].w;
			if(sum == 1) break;
			int fu = fnd(u), fv = fnd(v);
			if(fu == fv) continue;
			fa[fu] = fv;
			ans += w;
		}
		
		cout << ans;
	} else {
		int ans = INF;
		
		for(int I = 0; I < (1 << k); I++){
			int res = 0, sum = n;
			
			for(int i = 1; i <= n + k; i++)
				fa[i] = i;
			
			for(int i = 1; i <= k; i++)
				if(I >> (i - 1) & 1){
					res += c[i];
					for(int j = 1; j <= n; j++)
						e[++tot] = {i + n, j, a[i][j]};
					sum++;
				}
			
			sort(e + 1, e + 1 + tot);
			for(int i = 1; i <= tot; i++){
				int u = e[i].u, v = e[i].v, w = e[i].w;
				if(sum == 1) break;
				if(res >= ans) break;
				int fu = fnd(u), fv = fnd(v);
				if(fu == fv) continue;
				fa[fu] = fv;
				res += w;
			}
			
			ans = min(ans, res);
			tot = m;
		}
		
		cout << ans;
	}
}

/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4 
*/

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--)
		solve();
	return 0;
}
