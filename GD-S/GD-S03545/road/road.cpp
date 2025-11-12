#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int M = 1e7+100;
const int N = 1e4+100;
const int K = 30;
const ll INF = 1e18+100;

struct R {
	int u, v, w, lst;
}road[M<<1];

int final[M], tot, c[K], a[K][N], fa[N];

void add (int u, int v, int w) {
	road[++tot].u = u, road[tot].v = v, road[tot].w = w, road[tot].lst = final[u], final[u] = tot;
}

bool cmp (R x, R y) {
	return x.w < y.w;
}

int find (int a) {
	if (fa[a] == a) return a;
	return fa[a] = find(fa[a]);
}

void merge (int a, int b) {
	int faa = find(fa[a]), fab = find(fa[b]);
	if (faa != fab) fa[faa] = fab;
}

void solve () {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 1;i <= m;i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	bool flag = true;
	for (int i = 1;i <= n+k;i++) fa[i] = i;
	for (int i = 1;i <= k;i++) {
		scanf("%d", c+i);
		if (c[i]) flag = false;
		for (int j = 1;j <= n;j++) 
			scanf("%d", &a[i][j]);
	}
	
	if (!k) {
		sort(road+1, road+tot+1, cmp);
		ll ans = 0, cnt = 0;
		for (int i = 1;i <= tot;i++) {
			int u = road[i].u, v = road[i].v;
			if (cnt >= (n-1)) break;
			if (find(u) != find(v)) merge(u, v), ans += road[i].w, cnt++;
		}
		printf("%lld\n", ans);
		return;
	}
	if (flag) {
		for (int i = 1;i <= k;i++) {
			int point = n+i;
			for (int j = 1;j <= n;j++) 
				add(point, j, a[i][j]);
		}
		sort(road+1, road+tot+1, cmp);
		ll ans = 0, cnt = 0;
		n += k;
		for (int i = 1;i <= tot;i++) {
			int u = road[i].u, v = road[i].v;
			if (cnt >= (n-1)) break;
			if (find(u) != find(v)) merge(u, v), ans += road[i].w, cnt++;
		}
		printf("%lld\n", ans);
		return;
	}
	if (k <= 10) {
		ll ans = INF, use = tot;
		for (int i = 0;i <= ((1<<k)-1);i++) {
			int tmp = i, id = 1;
			ll res = 0;
			set <int> s;
			while (tmp) {
				if (tmp%2) s.insert(id);
				tmp >>= 1; id++;
				
			}
			tot = use;
			for (auto i : s) {
				int point = n+i; res += c[i];
				for (int j = 1;j <= n;j++)
					add(point, j, a[i][j]);
			}
			sort(road+1, road+tot+1, cmp);
			ll cnt = 0;
			n += s.size();
			for (int i = 1;i <= n;i++) fa[i] = i;
			for (int i = 1;i <= tot;i++) {
				int u = road[i].u, v = road[i].v;
				if (cnt >= n-1) break;
				if (find(u) != find(v)) merge(u, v), res += road[i].w, cnt++;
			}
			ans = min(ans, res);
		}
		printf("%lld\n", ans);
		return;
	}
}

int main () {
	freopen("road.in","r", stdin);
	freopen("road.out", "w", stdout);
	int _ = 1;
	while(_--) solve();
	return 0;
}

