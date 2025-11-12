#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
using namespace std;

const int N=1e4+10, M=1e6+10, K=20;
int n, m, k, cnt;
int fa[N], f[N], c[N], a[N];
bool flag;
ll ans;
vector <int> G[N];

struct edge {
	int u, v, w;
}e[M*3];

bool cmp (edge a1, edge a2) {return a1.w < a2.w;}

int find (int u) {
	if (fa[u] == u) return u;
	return fa[u]=find (fa[u]);
}

int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> m >> k; ans=0;
	for (int i=1; i <= n; i++) fa[i]=i;
	for (int i=1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	cnt=m;
	for (int i=1; i <= k; i++) {
		cin >> c[i];
		if (c[i]) flag=1; int now=0;
		for (int j=1; j <= n; j++) {
			cin >> a[j];
			if (a[j] == 0) now=j;
		}
		for (int j=1; j <= n; j++) {
			if (j != now) e[++cnt]={j, now, a[j]};
		}
	}
//	cout << cnt << '\n';
	if (k > 0 && flag) return 0;
	sort (e+1, e+cnt+1, cmp);
	for (int i=1; i <= cnt; i++) {
		if (find (e[i].u) == find (e[i].v) ) continue;
		fa[find (e[i].u)]=find (e[i].v);
		ans+=e[i].w;
	}
	cout << ans;
	return 0;
}

