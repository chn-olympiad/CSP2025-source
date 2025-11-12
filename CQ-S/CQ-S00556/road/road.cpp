#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 5, M = 1e6 + 5, K = 12;
int n, m, k, x[M], y[M], z[M], g[K], a[K][N];
int nume, numee, fa[N], fx, fy, cnt, tot;
int ans1, ans2, s, ans = 1e18;
int L1, L2;
struct node{
	int x, y, z;
} e[2 * M], ee[2 * M], eee[2 * M];
inline int min_(int aa, int bb){
	return aa < bb ? aa : bb;
}
inline bool cmp(node xx, node yy){
	return xx.z < yy.z;
}
inline int find(int aa){
	if(fa[aa] == aa) return aa;
	else return fa[aa] = find(fa[aa]);
}
inline int get_ans(int nn){
	cnt = tot = 0;
	for(int i = 1; i < N; i++) fa[i] = i;
	for(int i = m + 1; i <= nume; i++) eee[i] = e[i];
	sort(e + m + 1, e + nume + 1, cmp);
	L1 = 1;
	L2 = m + 1;
	numee = 0;
	while(L1 <= m && L2 <= nume){
		if(e[L1].z < e[L2].z){
			ee[++numee] = e[L1];
			L1++;
		}else{
			ee[++numee] = e[L2];
			L2++;
		}
	}
	while(L1 <= m){
		ee[++numee] = e[L1];
		L1++;
	}
	while(L2 <= numee){
		ee[++numee] = e[L2];
		L2++;
	}
	for(int i = m + 1; i <= nume; i++) e[i] = eee[i];
	for(int i = 1; i <= nume; i++){
		fx = find(ee[i].x);
		fy = find(ee[i].y);
		if(fx == fy) continue;
		fa[fx] = fy;
		tot += ee[i].z;
		cnt++;
		if(cnt == nn - 1) break;
	}
	return tot;
}
inline void dfs(int num, int nn, int rr){
	if(num == k){
		ans = min_(ans, get_ans(nn) + rr);
		return ;
	}
	dfs(num + 1, nn, rr);
	for(int j = 1; j <= n; j++) e[++nume] = {num + 1 + n, j, a[num + 1][j]};
	dfs(num + 1, nn + 1, rr + g[num + 1]);
	for(int j = 1; j <= n; j++) nume--;
	return ;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for(int j = 1; j <= m; j++){
		cin >> x[j] >> y[j] >> z[j];
		e[++nume] = {x[j], y[j], z[j]};
	}
	sort(e + 1, e + nume + 1, cmp);
	for(int i = 1; i <= k; i++){
		cin >> g[i];
		for(int j = 1; j <= n; j++) cin >> a[i][j];
	}
	dfs(0, n, 0);
	cout << ans;
	return 0;
}
