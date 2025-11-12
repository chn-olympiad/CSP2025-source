#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

const int N = 1e4 + 20, M = 1e6 + 1e5 + 10, K = 20;
int n, n2, m, k, u, v, w, fa[N], c[K], a[K][N], mn[N], cnt, idx[K];
ll ans, s; bool vis[N], d[N];

struct pii{
	int u, v, w;
	
	bool operator < (const pii & o) const{
		return w < o.w;
	}
} b[M], g[K][N];

int fr(int u){
	if(u == fa[u]) return u;
	return fa[u] = fr(fa[u]);
}

void get_node(int & ru, int & rv, int & w){
	int mn = 1e9, chs;
	for(int i = 0; i <= k; i++){
		if(d[i] && idx[i] < n && g[i][idx[i]+1].w < mn){
			u = g[i][idx[i]+1].u;
			v = g[i][idx[i]+1].v;
			mn = g[i][idx[i]+1].w;
			chs = i;
		}
	}
	idx[chs]++;
//	if(fr(u) != fr(v)) cout << u << ' ' << v << ' ' << mn << '\n';
	ru = fr(u), rv = fr(v), w = mn;
}

void dfs(int x){
	if(x == k+1){
		s = cnt = 0;
		for(int i = 1; i <= k; i++){
			if(d[i]) s += c[i];
		}
		for(int i = 0; i <= k; i++) idx[i] = 0;
		for(int i = 1; i <= n+k; i++) fa[i] = i;
		while(cnt < n+n2-1){
			int ru, rv, w;
			get_node(ru, rv, w);
			if(ru != rv){
				fa[ru] = rv;
				s += w;
				cnt++;
				if(cnt == n+n2-1) break;
			}
		}
//		cout << s << '\n';
		ans = min(ans, s);
		return;
	}
	d[x] = 0;
	dfs(x+1);
	n2++;
	d[x] = 1;
	dfs(x+1);
	n2--;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k; ans = 1e18; d[0] = 1;
	for(int i = 1; i <= m; i++){
		cin >> b[i].u >> b[i].v >> b[i].w;
	}
	sort(b + 1, b + 1 + m);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		int ru = fr(b[i].u), rv = fr(b[i].v);
		if(ru != rv){
			fa[ru] = rv;
			g[0][++cnt] = b[i];
		}
	}
	g[0][n].w = 1e9;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			g[i][j].u = i+n;
			g[i][j].v = j;
			g[i][j].w = a[i][j];
//			cout << g[i][j].u << ' ' << g[i][j].v << ' ' << g[i][j].w << '\n';
		}
		sort(g[i] + 1, g[i] + 1 + n);
	}
	dfs(1);
	cout << ans << '\n';
	return 0;
}
