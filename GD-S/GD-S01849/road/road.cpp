#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1e4 + 5, M = 1e6 + 5, K = 15;
int n, m, k, f[N + K], chs[K];
struct Node{
	int u, v;
	LL w;
	bool operator < (const Node &t) const{
		return w < t.w;
	}
}E[M], e[M + N * K], in[N];
LL c[K], a[K][N], ans;
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]); 
}
LL calc(int all, int tot){
	for(int i = 1; i <= n + k; ++i) f[i] = i;
	sort(e + 1, e + tot + 1);
	LL res = 0;
	int cnt = 0;
	for(int i = 1; i <= tot; ++i){
		int x = find(e[i].u), y = find(e[i].v);
		if(x == y) continue;
		f[x] = y;
		cnt++;
		res += e[i].w;
		if(all == n) in[cnt] = e[i];
		if(cnt == all - 1) break;
	}
	return res;
}
void dfs(int cur, int cnt){
	if(cur > k){
		if(!cnt) return ;
		LL sum = 0;
		int tot = 0;
		for(int i = 1; i <= cnt; ++i){
			sum += c[chs[i]];
			for(int j = 1; j <= n; ++j) e[++tot] = (Node){chs[i] + n, j, a[chs[i]][j]};
		}
		for(int i = 1; i < n; ++i) e[++tot] = in[i];
		ans = min(ans, sum + calc(n + cnt, tot));
		return ;
	}
	dfs(cur + 1, cnt);
	chs[cnt + 1] = cur;
	dfs(cur + 1, cnt + 1);
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) cin >> E[i].u >> E[i].v >> E[i].w;
	for(int i = 1; i <= k; ++i){
		cin >> c[i];
		for(int j = 1; j <= n; ++j) cin >> a[i][j];
	}
	for(int i = 1; i <= m; ++i) e[i] = E[i];
	ans = calc(n, m);
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
