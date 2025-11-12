#include <bits/stdc++.h>
using namespace std;
int n, m, kk;
struct edge {
	int x, y, val;
} arr[10024][12];
int a[12][10004], w[12];
int cnt = 0;
long long res;
long long ans[12];
bool operator < (edge x, edge y) {
	return x.val > y.val;
}
priority_queue<edge> q;
inline void ins(int x, int y, int v) {
	edge t;
	t.x = x;
	t.y = y;
	t.val = v;
	q.push(t);
}
int par[10024];
inline int getRoot(int x) {
	int root = x;
	while (par[root] > 0) root = par[root];
	while (x ^ root) {
		int cur = x;
		x = par[x];
		par[cur] = root;
	}
	return root;
}
inline bool merge(int x, int y) {
	int rx = getRoot(x);
	int ry = getRoot(y);
	if (rx == ry) return false;
	if (par[rx] > par[ry]) swap(rx, ry);
	par[rx] += par[ry];
	par[ry] = rx;
	return true;
}
int sum[12];
void dfs(int k, int r) {
	if (k) {
		memset(par, -1, sizeof par);
		ans[k] = w[r] + sum[k - 1];
		sum[k] = ans[k];
		q = priority_queue<edge>();
		for (int i = 1; i < n + k - 1; i++) {
			q.push(arr[i][k - 1]);
		}
		for (int i = 1; i <= n; i++) {
			edge t;
			t.x = n + k;
			t.y = i;
			t.val = a[r][i];
			q.push(t);
		}
		//cout << "114514\n";
		cnt = 0;
		while (cnt < n + k - 1) {
			edge e = q.top();
			q.pop();
			if (merge(e.x, e.y)) {
				//cout << e.x << ' ' << e.y << '\n';
				cnt++;
				arr[cnt][k] = e;
				ans[k] += e.val;
			}
		}
		res = min(ans[k], res);
		//cout << ans[k] << '\n';
	}
	for (int i = r + 1; i <= kk; i++) {
		dfs(k + 1, i);
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(par, -1, sizeof par);
	scanf("%d %d %d", &n, &m, &kk);
	for (int i = 1; i <= m; i++) {
		int x, y, v;
		scanf("%d %d %d", &x, &y, &v);
		ins(x, y, v);
	}
	while (cnt < n - 1) {
		edge e = q.top();
		q.pop();
		if (merge(e.x, e.y)) {
			cnt++;
			ans[0] += e.val;
			arr[cnt][0] = e;
		}
	}
	res = ans[0];/*
	for (int i = 1; i < n; i++) {
		cout << arr[i][0].x << ' ' << arr[i][0].y << ' ' << arr[i][0].val << '\n';
	}*/
	//cout << ans[0] << '\n';
	for (int i = 1; i <= kk; i++) {
		scanf("%d", w + i);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	dfs(0, 0);
	printf("%lld", res);
	return 0;
}
