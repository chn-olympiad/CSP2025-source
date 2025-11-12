#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e4 + 5;
const int M = 2 * 1e6 + 5;

int n, m, k, len, cnt, pos;
int fa[N];
ll c[N], ans;

inline ll Read() {
	int sum = 0, fl = 1;
	int ch = getchar();
	for (; !isdigit(ch); ch = getchar())
	if (ch == '-') fl = -1;
	for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * fl;
}

struct Edge {
	int u, v, id; ll w;
} e[M];

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

int find(int x) {
	if (x == fa[x]) {
		return x;
	} return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	fa[fx] = fy;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	n = Read(), m = Read(), k = Read();
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		e[i].u = Read();
		e[i].v = Read();
		e[i].w = Read();
		e[i].id = i;
	} 
	for (int i = 1; i <= k; i++) {
		c[i] = Read();
		for (int j = 1; j <= n; j++) {
			int idx = (i - 1) * n + j + m;
			e[idx].v = j;
			e[idx].w = Read();
			e[i].id = idx;
			if (e[idx].w == 0) {
				pos = j;
			} 
			if (i == j) {
				c[i] += e[idx].w;
			}
		}
		for (int j = 1; j <= n; j++) {
			int idx = (i - 1) * n + j + m;
			e[idx].u = pos;
		}
	}
	len = m + n * k;
	sort(e + 1, e + 1 + len, cmp);
	for (int i = 1; i <= len; i++) {
		int fu = find(e[i].u);
		int fv = find(e[i].v);
		if (fu != fv) {
			merge(fu, fv);
			ans += e[i].w;
			cnt++;
		}
		if (cnt == n - 1) {
			break;
		}
	}
	printf("%lld", ans);

	return 0;
}
// 15:23,发现城市化的城市还要加上自环
// 15:24,绝望，安慰自己还有前四个点呢 
// 15:27,不对啊，样例里面不是a[j][i] = 0? 
// 15:31,很好很好，现在48分了 
