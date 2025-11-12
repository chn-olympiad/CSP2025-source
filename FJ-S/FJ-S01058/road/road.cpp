#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
il int rd(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) s = ((s << 1) + (s << 3) + ch - 48);
	return s * w;
}
const int N = 10015, M = 1000105;
int n, m, k, fa[N], c[N], idkl[15], idkr[15], tot;
int id[(1 << 10) + 5][N + 15], cnt[(1 << 10) + 5];
ll val[(1 << 10) + 5];
struct Edge{int u, v, w;}e[M + 10 * N];
il bool cmp(Edge a, Edge b){return a.w < b.w;}
il int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
il void work(int s, int sub, int t){
	int ct = 0;
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	for (int i = 0; i < k; i++) if ((s >> i) & 1) val[s] += c[i], ct++;
	for (int i = 1, j = idkl[t]; (i < n || j <= idkr[t]) && cnt[s] < n + ct - 1;){
		int now;
		if (i >= n || cmp(e[id[sub][i]], e[j])) now = id[sub][i++];
		else now = j++;
		int u = find(e[now].u), v = find(e[now].v), w = e[now].w;
		if (u == v) continue;
		val[s] += w, fa[u] = v, id[s][++cnt[s]] = now;
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = rd(), m = rd(), k = rd(), tot = m;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) e[i] = Edge{rd(), rd(), rd()};
	for (int i = 0; i < k; i++){
		idkl[i] = tot + 1, c[i] = rd();
		for (int j = 1; j <= n; j++) e[++tot] = Edge{n + i + 1, j, rd()};
		idkr[i] = tot, sort(e + idkl[i], e + idkr[i] + 1, cmp);
	}
	sort (e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m && cnt[0] < n - 1; i++){
		int u = find(e[i].u), v = find(e[i].v), w = e[i].w;
		if (u == v) continue;
		val[0] += w, fa[u] = v, id[0][++cnt[0]] = i;
	}
	ll ans = val[0];
	for (int s = 1; s < (1 << k); s++){
		int t;
		for (t = 0; t < k; t++) if ((s >> t) & 1) break;
		work(s, s ^ (1 << t), t), ans = min(ans, val[s]);
	}
	printf ("%lld\n", ans);
	return 0;
}

