// GZ-S00471 贵阳市第一中学 陈昱竹
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6+50;
int is_built[15][2];
int n, m, fth;
int u, v, fa[N];
ll w, wt, gs, gss;

struct node {
	int u, v;
	ll len, extralen;
} a[N];
int k;

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void add(int u, int v, ll w, ll el) {
	a[++k].u = u;
	a[k].v = v;
	a[k].len = w;
	a[k].extralen = el;
	return;
}

bool cmp(node n1, node n2) {
	return (n1.len+n1.extralen) < (n2.len+n2.extralen);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &fth);
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &u, &v, &w);
		add(u, v, w, 0);
		add(v, u, w, 0);
	}
	for(int i = 1; i <= fth; i++) {
		scanf("%lld", &gs);
		v = n+i;
		is_built[i][1] = gs;
		for(int j = 1; j <= n; j++) {
			u = j;
			scanf("%lld", &gss);
			add(u, v, gss, gs);
			add(v, u, gss, gs);
		}
	}
	sort(a+1, a+1+k, cmp);
	for(int i = 1; i <= k; i++) {
		int x = a[i].u;
		int y = a[i].v;
		int fx = find(x);
		int fy = find(y);
		if(fx != fy) {
			wt += a[i].len;
			int extrabuiltx = x-n;
			int extrabuilty = y-n;
			if(extrabuiltx > 0 || extrabuilty > 0) {
				if(extrabuiltx > 0 && !is_built[extrabuiltx][0]) {
					wt += is_built[extrabuiltx][1];
					is_built[extrabuiltx][0] = 1;
				} else if(extrabuilty > 0 && !is_built[extrabuilty][0]) {
					wt += is_built[extrabuilty][1];
					is_built[extrabuilty][0] = 1;
				}
			}
			fa[fx] = fy;
		}
	}
	printf("%lld", wt);
	return 0;
}
