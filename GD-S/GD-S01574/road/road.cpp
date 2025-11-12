#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int fa[10005];
struct node{
	int to, v;
};
struct edge{
	int s, t, v;
};
bool cmp(edge a, edge b) {
	return a.v < b.v;
}
int f(int x) {
	if (fa[x] == x) return x;
	return fa[x] = f(fa[x]);
}
vector<node> g[10005];
vector<node> g2[10005];
edge e[2000005];
int bd[10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1 ; i <= n + k ; i++) fa[i] = i;
	for (int i = 1 ; i <= m ; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({b, c});
		g[b].push_back({a, c});
		e[i] = {a, b, c};
	}
	for (int i = 1 ; i <= k ; i++) {
		scanf("%d", &bd[i]);
		for (int j = 1 ; j <= n ; j++) {
			int a;
			scanf("%d", &a);
			g2[j].push_back({n + i, a});
			g2[n + i].push_back({j, a});
		}
	}
	if (k == 0) {
		sort(e + 1, e + 1 + m, cmp);
		int ans = 0;
		for (int i = 1 ; i <= m ; i++) {
			if (f(e[i].s) != f(e[i].t)) {
				ans += e[i].v;
				fa[f(e[i].s)] = f(e[i].t);
			}
		}
		cout << ans; 
	} else {
		for (int i = 1 ; i <= k ; i++) {
			for (node j : g2[n + i]) {
				e[++m] = {n + i, j.to, j.v};
			}
		}
		sort(e + 1, e + 1 + m, cmp);
	int ans = 0;
	for (int i = 1 ; i <= m ; i++) {
		if (f(e[i].s) != f(e[i].t)) {
			ans += e[i].v;
			fa[f(e[i].s)] = f(e[i].t);
		}
	}
		cout << ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

