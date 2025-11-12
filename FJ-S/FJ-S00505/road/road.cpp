#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <set>
#include <map>
using namespace std;

#define ll long long
#define MAX_N 10000
#define MAX_M 1000000
#define MAX_K 10
struct Edge {
	int u, v, w;
} edge[MAX_M + MAX_K * MAX_N + 5];
int n, m, k, te, yu, fa[MAX_N + MAX_K + 5], is_ans[MAX_K + 5];
ll ans;
ll yu_ans[MAX_K + 5];

int Read() {
	int sum = 0, ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') {
		sum = (sum << 1) + (sum << 3) + ch - '0';
		ch = getchar();
	}
	return sum;
}
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
int Find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}
void Union(int x, int y, int val) {
	int c = -1;
	if (x > n) c = x - n;
	if (y > n) c = y - n;
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	fa[x] = y;
	if (c != -1) {
		is_ans[c]++;
		yu_ans[c] += 1ll * val;
		return;
	}
	ans += 1ll * val;
	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = Read();
	m = Read();
	k = Read();
	int u, v, w, tmp;
	for (int i = 1; i <= m; i++) {
		u = Read();
		v = Read();
		w = Read();
		te++;
		edge[te].u = u;
		edge[te].v = v;
		edge[te].w = w;
	}
	for (int i = 1; i <= k; i++) {
		tmp = Read();
		for (int j = 1; j <= n; j++) {
			tmp = Read();
			te++;
			edge[te].u = n + i;
			edge[te].v = j;
			edge[te].w = tmp;
		}
	}
	sort(edge + 1, edge + 1 + te, cmp);
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	for (int i = 1; i <= te; i++) 
		Union(edge[i].u, edge[i].v, edge[i].w);
	for (int i = 1; i <= k; i++) 
		if (is_ans[i] > 1) ans += yu_ans[i];
	printf("%lld", ans);
	return 0;
}

