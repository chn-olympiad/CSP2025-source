#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int MaxN = 1e4 + 30, MaxM = 1e6 + MaxN * 20 + 10;

struct E {
	int x, y, w, id;
	
	bool operator<(const E &j) const {
		return w < j.w;
	}
} e[MaxM];

int fa[MaxN], indeg[MaxN], c[MaxN][20], n, m, k, ans = 1e18;
bool vis[MaxM];

bool cmp(E a, E b) {
	return a.id < b.id;
}

int ff(int x) {
	return fa[x] < 0 ? x : fa[x] = ff(fa[x]);
}

bool merge(int x, int y) {
	x = ff(x), y = ff(y);
	if (x == y) return 0;
	if (fa[x] > fa[y]) swap(x, y);
	fa[x] += fa[y], fa[y] = x;
	return 1;
}

int GO(int chek, int res = 0, int cnt = 0) {
	for (int i = 1; i <= n + k; i++) {
		fa[i] = -1;
	}
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++) {
		if (merge(e[i].x, e[i].y)) res += e[i].w, cnt++;
	}
	sort(e +1, e + m + 1, cmp);
	if (cnt != chek - 1) return 1e9;
	return res;
} 

void DFS(int x, int chek = n, int sum = 0) {
	if (GO(chek) + sum >= ans) return; // 剪枝，因为加一个肯定是管一个环的答案，所以如果不更优秀就不成为答案 
	if (x == k + 1) {
		ans = min(ans, GO(chek) + sum);
		return;	
	}
	DFS(x + 1, chek, sum);
	sum += c[x + n][0];
	for (int i = 1; i <= n; i++) {
		m++;
		e[m] = {n + x, i, c[x +n][i], m};
	}
	DFS(x + 1, chek + 1, sum);
	sum -= c[x + n][0];
	m -= n;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e[i] = {u, v, w, i};
	}
	bool flag = 1;
	for (int i = 1; i <= k; i++) {
		cin >> c[i + n][0];
		flag &= c[i + n][0] == 0;
		for (int j = 1; j <= n; j++) {
			cin >> c[i + n][j];
			flag &= c[i + n][j] == 0;
		}
	}
	if (flag) {
		cout << 0 << '\n';
	} else {
		DFS(1);
		cout << ans << '\n';
	}
	return 0;
}
