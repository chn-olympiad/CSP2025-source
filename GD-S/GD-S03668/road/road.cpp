#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL MAXN = 1e4+5, MAXM = 2*(1e6)+(2e5)+5;
struct E{
	LL u, v, w;
} edge[MAXM];
LL n, m, k, elen, fa[MAXN];
//LL tot, to[MAXM], nxt[MAXM], head[MAXN], wth[MAXM];
 
bool cmp(E x, E y) {
	return x.w < y.w;
}

//void adde(LL u, LL v, LL w) {
//	to[++tot] = v;
//	nxt[tot] = head[u];
//	head[u] = tot;
//	wth[tot] = w;
//}

LL fd(LL x) {
	if (fa[x] == x) return x;
	return fa[x] = fd(fa[x]);
}

void mrg(LL x, LL y) {
	fa[fd(x)] = fd(y);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	LL u, v, w;
	for (LL i = 1; i<=m; i++) {
		cin >>u >> v >> w;
		edge[++elen] = { u, v, w };
//		adde(u, v, w), adde(v, u, w);
	}
	if (k == 0) {
		for (LL i = 1; i<=n; i++) fa[i] = i;
		sort(edge+1, edge+1+elen, cmp);
		LL ans = 0, nd = n;
		for (LL i = 1; nd>1 && i<=elen; i++) {
			u = edge[i].u, v = edge[i].v, w = edge[i].w;
			u = fd(u), v = fd(v);
			if (u != v) {
				ans += w;
				mrg(u, v);
				nd--;
			}
		}
		cout << ans;
		return 0;
	}
	bool isa = true;
	LL cj;
	for (LL i = 1; i<=n+k; i++) fa[i] = i;
	LL ans = 0, nd = n+k; // 这么多点 
	for (LL i = 1; i<=k; i++) {
		cin >> cj;
		if (cj) isa = false;
		for (LL j = 1; j<=n; j++) {
			cin >> w;
			edge[++elen] = { n+i, j, w };
		}
	}
	sort(edge+1, edge+1+elen, cmp);
	for (LL i = 1; nd>1 && i<=elen; i++) {
		u = edge[i].u, v = edge[i].v, w = edge[i].w;
		u = fd(u), v = fd(v);
//		cout << "nd:" << nd << " edge: " <<  u << " to " << v << endl;
		if (u != v) {
			ans += w;
			mrg(u, v);
			nd--;
		}
	}
	cout << ans;
	return 0;
}
