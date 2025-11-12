#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define PII pair<int,int>
using namespace std;

const int maxn = 2e4+111, maxm = 1e6+111;

int n, m, k;

int fa[maxn];
struct node {
	int u;
	int v;
	int w;
} e[maxn * 2];
bool cmp(node x, node y) {
	return x.w < y.w;
}
void read() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[i] = {u, v, w};
	}
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
}
int Find(int x) {
	if (fa[x] != x) return fa[x] = Find(fa[x]);
	return x;
}
int cnt;
int ans;

void ku() {
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; ++i) {
		if (cnt == n - 1) break;
		int u = e[i].u;
		int v = e[i].v;
		int fu = Find(u);
		int fv = Find(v);
		if (fu != fv) {
			fa[fu] = fv;
			++cnt;
			ans += e[i].w;
		}
	}
}

void solve() {
	read();
	if (k == 0) {
		ku();
		printf("%d", ans);
	} else cout << 0;
}

signed main() {
//	freopen("1.in", "r", stdin);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	solve();

	return 0;
}