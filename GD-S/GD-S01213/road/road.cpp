#include <bits/stdc++.h>
using namespace std;

//Òª¿ªlong long 
struct JZ {
	int u, v;
	long long w;
}a[2000005], t[100005], tt[1000005];
int n, m, k, cnt;
long long sum, ans;
int fa[20005];
bool vis[15];
long long c[15], b[15][10005], minn[15][10005];
bool cmp(JZ x, JZ y) {
	return x.w < y.w;
}
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	fa[find(x)] = find(y);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) scanf("%d %d %lld", &a[i].u, &a[i].v, &a[i].w);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) scanf("%lld", &b[i][j]);
	}
	sort(a+1, a+m+1, cmp);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		if (cnt == n-1) break;
		if (find(a[i].u) != find(a[i].v)) {
			merge(a[i].u, a[i].v); 
			sum += a[i].w, cnt++;
			t[cnt] = a[i];
		}
	} 
	ans = sum;
	for (int l = 1; l < (1<<k); l++) {
		int cur = cnt, pcnt = n, ecnt = 0;
		long long ssum = 0;
		for (int i = 1; i <= cnt; i++) tt[i] = t[i];
		for (int i = 1; i <= k; i++) {
			if ((l>>(i-1))&1) {
				pcnt++, ssum += c[i];
				for (int j = 1; j <= n; j++) tt[++cur] = {pcnt, j, b[i][j]};
			}
		}
		sort(tt+1, tt+cur+1, cmp);
		for (int i = 1; i <= pcnt; i++) fa[i] = i;
		for (int i = 1; i <= cur; i++) {
			if (ecnt == pcnt-1) break;
			if (find(tt[i].u) != find(tt[i].v)) {
				merge(tt[i].u, tt[i].v);
				ssum += tt[i].w, ecnt++;
			}
		}
		ans = min(ans, ssum);
	}
	printf("%lld\n", ans);
	return 0;
}
