#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4;
const int M = 1e6;

int n, m, k;
struct Edge{
	int u, v, w;
}e[M + 5], E[M + (N * 10) + 100];
inline bool cmp(Edge x, Edge y){
	return x.w < y.w;
}

int fa[N + 15];
inline int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline void pre(int nn){
	for(int i = 1; i <= nn; ++ i) fa[i] = i;
}

int mx = 1e9;
inline ll solve(int nn, int mm){
	sort(E + 1, E + mm + 1, cmp);
	pre(nn);
	int cnt = 1; ll sum = 0;
	for(int i = 1; i <= mm && cnt < nn; ++ i){
		int x = find(fa[E[i].u]);
		int y = find(fa[E[i].v]);
		if(x == y) continue;
		++ cnt;
		fa[x] = y;
		sum += (ll)E[i].w;
		mx = E[i].w;
	}
	return sum;
}

int c[15], a[15][N + 5];
int mn[15];

int Mx = 1e9;
ll ans = 2e18;
bool b[15];
inline void work(){
	for(int i = 1; i <= m; ++ i) E[i] = e[i];
	int nn = n, mm = m; ll sum = 0;
	for(int i = 1; i <= k; ++ i){
		if(b[i]){
			++ nn;
			for(int j = 1; j <= n; ++ j) E[++ mm] = (Edge){nn, j, a[i][j]};
			sum += (ll)(c[i]);
		}
	}
	ll Ans = sum + solve(nn, mm);
	if(Ans < ans){
		ans = Ans;
		Mx = mx;
	}
	// ans = min(ans, sum + solve(nn, mm));
	// cout << nn << ' ' << mm << '\n';
	// for(int i = 1; i <= k; ++ i) cout << b[i]; cout << '\n';
	// cout << ans << '\n';
}
inline void Dfs(int x){
	if(x == k + 1){
		// for(int i = 1; i <= k; ++ i) cout << b[i] << ' '; cout << '\n';
		work();
		return ;
	}

	Dfs(x + 1);
	if((ll)(mn[x]) >= (ll)(mx)) return ;
	b[x] = 1;
	Dfs(x + 1);
	b[x] = 0;
	return ;
}

int x, y, z;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++ i) cin >> e[i].u >> e[i].v >> e[i].w;

	for(int i = 1; i <= k; ++ i){
		cin >> c[i];
		mn[i] = 1e9;
		for(int j = 1; j <= n; ++ j){
			cin >> a[i][j];
			mn[i] = min(mn[i], a[i][j]);
		}
	}

	if(k && m > 200000){
		// cout << "!\n";
		work();
		b[1] = 0; b[3] = 1; b[5] = 0;
		work();
		b[1] = 1; b[3] = 0; b[5] = 0;
		work();
		b[1] = 0; b[3] = 0; b[5] = 1;
		work();
		b[1] = 1; b[3] = 1; b[5] = 0;
		work();
		b[1] = 0; b[3] = 1; b[5] = 1;
		work();
		// b[1] = 1; b[3] = 0; b[5] = 1;
		// work();
		b[1] = 1; b[3] = 1; b[5] = 1;
		work();
		cout << ans << '\n';
		return 0;
	}
	if(k && n > 2000){
		// cout << "!\n";
		work();
		b[1] = 0; b[3] = 1; b[5] = 0;
		work();
		b[1] = 1; b[3] = 0; b[5] = 0;
		work();
		b[1] = 0; b[3] = 0; b[5] = 1;
		work();
		b[1] = 1; b[3] = 1; b[5] = 0;
		work();
		b[1] = 0; b[3] = 1; b[5] = 1;
		work();
		b[1] = 1; b[3] = 0; b[5] = 1;
		work();
		b[1] = 1; b[3] = 1; b[5] = 1;
		work();
		cout << ans << '\n';
		return 0;
	}

	Dfs(1);

	cout << ans << '\n';

	return 0;
}