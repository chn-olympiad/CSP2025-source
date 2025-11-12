#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long 
#define pii pair<int, int>
#define pb push_back
#define mse(x, y) memset(x, y, sizeof x)
#define mcp(x, y) memcpy(x, y, sizeof x)
#define viclear(x) vector<int>().swap(x)
#define vpiiclear(x) vector<pii>().swap(x)
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define drep(x, r, l) for(int x = r; x >= l; x--)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
using namespace std;

const int MAXN = 1e4 + 15, MAXM = 1e6 + 5, MAXK = 1030, inf = 0x0101010101010101;
int n, m, k, c[15], fa[MAXN], siz[MAXN], Sum, ans = inf;
struct edge{ int u, v, w; } E[MAXM];
vector<edge> nowE[MAXK], e[15];

bool cmp(edge x, edge y){ return x.w < y.w; }

int lowbit(int x){ return -x & x; }

void init(){ Sum = 0; rep(i, 1, n + k) fa[i] = i, siz[i] = 1; }

int Get(int x){ return (fa[x] == x ? x : fa[x] = Get(fa[x])); }

void merge(int x, int y){
	x = Get(x), y = Get(y);
	if(x == y) return ;
	if(siz[x] < siz[y]) swap(x, y);
	fa[y] = x, siz[x] += siz[y];
}

int G(int x){
	int res = 1;
	while(x != 1) res++, x /= 2;
	return res;
}

int Gnum(int x){
	int res = 0;
	while(x) x -= lowbit(x), res++;
	return res;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	FASTIO;
	cin >> n >> m >> k;
	rep(i, 1, m) cin >> E[i].u >> E[i].v >> E[i].w;
	sort(E + 1, E + m + 1, cmp);
	init();
	rep(i, 1, m){
		int u = E[i].u, v = E[i].v, w = E[i].w;
		if(Get(u) == Get(v)) continue;
		Sum += w;
		merge(u, v), nowE[0].pb(E[i]);
	}
	ans = min(ans, Sum);
	rep(i, 1, k){
		cin >> c[i];
		rep(j, 1, n){
			int w;
			cin >> w;
			e[i].pb( {i + n, j, w} );
		}
		sort(e[i].begin(), e[i].end(), cmp);
	}
	rep(i, 1, (1 << k) - 1){
		init();
		int o = i;
		while(o) Sum += c[G(lowbit(o))], o -= lowbit(o);
		int p = 0, q = 0, msk = i - lowbit(i), las = G(lowbit(i)), cnt = n + Gnum(i);
		while(cnt != 1){
			if(q != (int)e[las].size() && (p == (int)nowE[msk].size() || e[las][q].w < nowE[msk][p].w)){
				int u = e[las][q].u, v = e[las][q].v, w = e[las][q].w;
				if(Get(u) == Get(v)){
					q++;
					continue;
				}
				merge(u, v), Sum += w, nowE[i].pb(e[las][q]), q++, cnt--;
			}
			else{
				int u = nowE[msk][p].u, v = nowE[msk][p].v, w = nowE[msk][p].w;
				if(Get(u) == Get(v)){
					p++;
					continue;
				}
				merge(u, v), Sum += w, nowE[i].pb(nowE[msk][p]), p++, cnt--;
			}
		}
		ans = min(ans, Sum);
	}
	cout << ans;
    return 0;
}

