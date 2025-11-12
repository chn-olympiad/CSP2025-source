#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

inline long long read(){
	long long res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
	return res;
}

long long n, m, k, fa[10005], uu[10005], vv[10005], ww[10005], g[12][10005], c[12];
long long sum;
inline long long find(long long x) {
	if (fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

struct node{
	long long u, v, w;
}edge[1000006];

bool cmp(node a, node b){return a.w <= b.w;}

void krusal(){
	sort(edge + 1, edge + m + 1, cmp);

	for (int i = 1; i <= n; i++) fa[i] = i;
	int cnt = 1;
	for (int i = 1; i <= m; i++) {
		int fu = find(edge[i].u), fv = find(edge[i].v);
		if (fu != fv) {
			fa[fu] = fv;
			uu[cnt] = edge[i].u, vv[cnt] = edge[i].v, ww[cnt] = edge[i].w;
			cnt++;
			sum += edge[i].w;
			if (cnt == n) break;
		}
	}
	for (int i = 1; i < n; i++) edge[i].u = uu[i], edge[i].v = vv[i], edge[i].w = ww[i];
	m = n - 1;
	return;
}

void solve(int x) {
	int cnt1 = 0;
	long long ans = 0;
	for (int i = 1; i <= k; i++)
		if ((1 << (i - 1)) & x) {
			cnt1++;
			for (int j = m + 1; j <= n + m; j++) {
				edge[j].u = cnt1 + n, edge[j].v = j - m, edge[j].w = g[i][j - m];
			}
			ans += c[i];
			m += n;
		}
	n += cnt1;
	sort(edge + 1, edge + m + 1, cmp);
	for (int i = 1; i <= n; i++) fa[i] = i;

	int cnt = 1;
	for (int i = 1; i <= m; i++) {
		int fu = find(edge[i].u), fv = find(edge[i].v);
		if (fu != fv) {
			fa[fu] = fv;
			cnt++;
			ans += edge[i].w;
			if (cnt == n) break;
		}
	}
	sum = min(sum, ans);
	n -= cnt1;
	for (int i = 1; i < n; i++) edge[i].u = uu[i], edge[i].v = vv[i], edge[i].w = ww[i];
	m = n - 1;
	//cout << "\n";
	return;
}


int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		edge[i].u = read(); edge[i].v = read(); edge[i].w = read();
	}
	krusal();
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++) g[i][j] = read();
	}
	for (int i = 1; i < (1 << k); i++) solve(i);
	cout << sum << "\n";
	return 0;
}