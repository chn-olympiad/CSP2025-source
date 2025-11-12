#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 2e5 + 7;
const int M = 1e6 + 7;
int n, m, k, cnt, maxn;
int fa[N], vis[N], sz[N];
ll c[N], ans = 1e18 + 7;

struct Edge{
	int u, v, id; ll w;
	bool operator<(const Edge & ed)const{
		return w < ed.w;
	}
}g1[M], g[N];

int Find(int x){
	if(fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}

void Merge(int x, int y){
	int xx = Find(x), yy = Find(y);
	fa[xx] = yy;
	sz[yy] += sz[xx]; maxn = max(maxn, sz[yy]);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i){
		cin >> g1[i].u >> g1[i].v >> g1[i].w;
	}
	sort(g1 + 1, g1 + m + 1);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= m; ++i){
		if(Find(g1[i].u) != Find(g1[i].v)){
			Merge(g1[i].u, g1[i].v);
			g[++cnt] = g1[i];
		}
	}
	for(int i = 1; i <= k; ++i){
		cin >> c[i];
		for(int j = 1; j <= n; ++j){
			cin >> g[++cnt].w;
			g[cnt].u = n + i; g[cnt].v = j; g[cnt].id = i;
		}
	}
	sort(g + 1, g + cnt + 1);
	for(int i = 0; i < (1 << k); ++i){
		ll tmp = 0, tmp2 = 0; maxn = 0;
		for(int j = 0; j < k; ++j){
			if(i & (1<<j)) vis[j+1] = 1, tmp += c[j+1], tmp2++;
			else vis[j+1] = 0;
		}
		for(int j = 1; j <= n+k; ++j) fa[j] = j, sz[j] = 1;
		for(int j = 1; j <= cnt; ++j){
			if(g[j].id != 0 && !vis[g[j].id]) continue;
			if(Find(g[j].u) != Find(g[j].v)){
				Merge(g[j].u, g[j].v);
				tmp += g[j].w;
				if(maxn >= n + tmp2) break;
			}
		}
		ans = min(ans, tmp);
	}
	cout << ans << "\n";
	return 0;
}