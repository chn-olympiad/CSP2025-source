#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXX = 1e5 + 5, MAXM = 1e6 + 5, MAXK = 11;

struct pp{
	int u, v, w;
} g[MAXX], e[MAXX], a[MAXM];

int s[MAXK][MAXX], c[MAXK], ans, fa[MAXX], sum[MAXX], cnt, n, m, k, vis[MAXK], tot;

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

bool cmp(pp a, pp b){
	return a.w < b.w;
}

void C(){
	int id = n;
	int num = 0;
	for(int i = 1; i <= k; i++){
		if(vis[i] == 1){
			id++;
			num += c[i];
		}
	}
	for(int i = 1; i <= n + k; i++){
		sum[i] = 1, fa[i] = i;
	}
	int i = 1, j = 1;
	while(1){
		int u, v, w;
		if(j == tot + 1){
			u = e[i].u, v = e[i].v, w = e[i].w;
			i++;
		}else if(i == cnt + 1){
			u = g[j].u, v = g[j].v, w = g[j].w;
			j++;
		}else if(e[i].w < g[j].w){
			u = e[i].u, v = e[i].v, w = e[i].w;
			i++;
		}else{
			u = g[j].u, v = g[j].v, w = g[j].w;
			j++;
		}
		if(u > n && vis[u - n] == 0) continue;
		int x = find(u), y = find(v);
		if(x != y){
			num += w;
			fa[x] = y;
			sum[y] += sum[x];
		}
		if(sum[y] == id){
			break;
		}
		if(num >= ans) return;
	}
	ans = min(ans, num);
}

void dfs(int x){
	if(x == k + 1){
		C();
		return;
	}
	vis[x] = 0;
	dfs(x + 1);
	vis[x] = 1;
	dfs(x + 1);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++) cin >> s[i][j], g[++tot] = (pp){n + i, j, s[i][j]};
	}
	sort(a + 1, a + 1 + m, cmp);
	sort(g + 1, g + 1 + tot, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i, sum[i] = 1;
	for(int i = 1; i <= m; i++){
		int x = find(a[i].u), y = find(a[i].v);
		if(x != y){
			ans += a[i].w;
			fa[x] = y;
			sum[y] += sum[x];
			e[++cnt] = a[i];
		}
		if(sum[y] == n){
			break;
		}
	}
	dfs(1);
	cout << ans << '\n';
	return 0;
} 
//两只鱼因，两只鱼因跑得快，跑得快！ 
