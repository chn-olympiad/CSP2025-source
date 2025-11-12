#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[20], a[20][20001], cnt2, tot, cnte; long long ans, res;
int fa[20001], siz[20001];
struct edge{int u, v, w;}e[1500000], e1[1500000], e2[200001];
bool cmp(edge a, edge b){return a.w < b.w;}
int find(int u){return (u == fa[u] ? u : fa[u] = find(fa[u]));}
void kruskal(){
	for (int i = 1; i <= tot; i++) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= cnte; i++){
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu != fv){
			if (siz[fu] > siz[fv]) swap(fu, fv);
			siz[fv] += siz[fu], fa[fu] = fv;
			ans += e[i].w; tot--;
			if (tot <= 1) break; 
		}
	}
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	res = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= m; i++) cin >> e1[i].u >> e1[i].v >> e1[i].w;
	sort(e1 + 1, e1 + m + 1, cmp);
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	for (int i = 0; i < (1 << k); i++){
		cnt2 = cnte = 0, tot = n, ans = 0;
		for (int j = 1; j <= k; j++) if (i & (1 << (j - 1))){
			tot++; ans += c[j];
			for (int l = 1; l <= n; l++) e2[++cnt2].u = l, e2[cnt2].v = tot, e2[cnt2].w = a[j][l];
		}
		sort(e2 + 1, e2 + cnt2 + 1, cmp);
		for (int j = 1, l = 1; cnte < m + cnt2; ){
			if ((e1[j].w < e2[l].w && j <= m) || l > cnt2) e[++cnte] = e1[j], j++;
			else e[++cnte] = e2[l], l++;
		}
		kruskal();
		res = min(res, ans);
	}
	cout << res << '\n';
	return 0;
}
/*
kruskal:O(m*alpha)(once,sorted)
total:O(2^k*m*alpha) 10^9+ not good, might get 64pts
*/
