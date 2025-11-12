#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector> 
using namespace std;
#define ll long long
const int N = 1e4+10, M = 1e6+10, K = 20;
int n, m, k, l;
struct Edge { int u, v, w; } ed[M<<1];
bool cmp (Edge e1, Edge e2) { return e1.w < e2.w; }
int c[K], a[K][N];

int fa[N];
int find (int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge (int x, int y) { fa[x] = y; }

Edge mtr[N][K][0];
int cnt = 0;
ll ans[K], ans1[K]; // 表示选和不选第 k 个  
Edge tree[M], t1[N], t2[N];

void init () {
	for (int i = 1; i <= n; i++) fa[i] = i;
}

void Solve () {
	for (int i = 1; i <= k; i++) {
		if (!c[i]) continue;
		if (ans[i-1] >= ans1[i-1]) { for(int j = 1; j < n; j++) mtr[j][i][0] = mtr[j][i-1][1]; }
		else { for(int j = 1; j < n; j++) mtr[j][i][0] = mtr[j][i-1][0]; } // 不选 
		
		for (int j = 1; j < n; j++) tree[j] = mtr[j][i-1][0];
		for (int j = 1; j <= n; j++) tree[n+j-1] = (Edge){i, j, a[i][j]};

		sort(tree+1, tree+1+n+n, cmp);
		init(); int fu, fv, len = 0; ll sum = c[i], sum1 = c[i];
		for (int j = 1; j < n+n; j++) {
			fu = find(tree[j].u), fv = find(tree[j].v);
			if (fu == fv) continue;
			merge(fu, fv);
			t1[++len] = tree[j];
			sum += tree[j].w;
		}
		
		for (int j = 1; j < n; j++) tree[j] = mtr[j][i-1][1];
		for (int j = 1; j <= n; j++) tree[n+j-1] = (Edge){i, j, a[i][j]};
		sort(tree+1, tree+n+n, cmp);
		init(); len = 0;
		for (int j = 1; j < n+n; j++) {
			fu = find(tree[j].u), fv = find(tree[j].v);
			if (fu == fv) continue;
			merge(fu, fv);
			t2[++len] = tree[j];
			sum1 += tree[j].w;
		}
		
		if (sum < sum1) for (int j = 1; j < n; j++) mtr[j][i][1] = t1[j];
		else for (int j = 1; j < n; j++) mtr[j][i][1] = t2[i];
		ans1[i] = max(sum, sum1);
	}
}

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ed[i].u, &ed[i].v, &ed[i].w);
	}
	l = m;
	for (int j = 1; j <= k; j++) {
		scanf("%d", &c[j]);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[j][i]);
			if (!c[j] && i != j) ed[++l] = (Edge){i, j, a[j][i]};
		}
	}
	init();
	sort(ed+1, ed+1+l, cmp);
	int fu, fv;
	for (int i = 1; i <= l; i++) {
		fu = find(ed[i].u), fv = find(ed[i].v);
		if (fu == fv) continue;
		merge(fu, fv);
		ans[0] = ans[1] = ans[0]+ed[i].w;
		mtr[++cnt][0][0] = mtr[cnt][0][1] = ed[i];
		// 选这条边  
	}
	//cout << ans[0] << endl;
	Solve();
	ll tot = ans[0];
	for (int i = 1; i <= k; i++) {
		if (!c[i]) continue;
		tot = min(tot, ans1[i]);
	}
	cout << tot << endl;
} 
