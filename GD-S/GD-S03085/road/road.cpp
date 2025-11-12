#include <bits/stdc++.h>
using namespace std;
int Read(int x = 0) {
	char c = getchar();
	while (!isdigit(c))
		c = getchar();
	while (isdigit(c))
		x = x * 10 + c - '0',
		c = getchar();
	return x;
}
struct edge {
	int x, y, z;
	bool operator < (const edge &e) const {
		return z < e.z;
	}
} e[1000005], c[11][100005];
int f[100005];
int find(int x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}
struct node {
	int x, d;
	bool operator < (const node &a) const {
		return d > a.d;
	}
};
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = Read(), m = Read(), k = Read();
	for (int i = 1; i <= m; i++)
		e[i] = (edge) {Read(), Read(), Read()};
	sort(e + 1, e + m + 1);
	int cnt = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++)
		if (find(e[i].x) != find(e[i].y)) {
			f[find(e[i].x)] = find(e[i].y);
			ans += e[i].z, e[++cnt] = e[i];
			if (cnt == n - 1) break;
		}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++)
			c[i][j] = (edge) {i, j, Read()};
		sort(c[i] + 1, c[i] + n + 1);
	}
	for (int i = 0; i < 1 << k; i++) {
		long long res = 0;
		int K = 0;
		for (int j = 1; j <= k; j++)
			if (i & (1 << j - 1))
				res += c[j][0].z, ++K;
		priority_queue <node> q;
		int nw[11] = {1}, cnt = 0;
		q.push((node) {0, e[1].z});
		for (int j = 1; j <= k; j++)
			if (i & (1 << j - 1))
				nw[j] = 1, q.push((node) {j, c[j][1].z});
		for (int j = 1; j <= n + k; j++) f[j] = j;
		while (1) {
			int x = q.top().x, z = q.top().d; q.pop();
			int y = nw[x]++;
			if (x) {if (nw[x] <= n) q.push((node) {x, c[x][nw[x]].z});}
			else if (nw[x] < n) q.push((node) {0, e[nw[x]].z});
			if (x) y = c[x][y].y, x += n;
			else x = e[y].x, y = e[y].y;
			if (find(x) != find(y)) {
				f[find(x)] = find(y);
				res += z, ++cnt;
				if (cnt == n + K - 1) break;
			}
		}
		ans = min(ans, res);
	}
	return printf("%lld", ans), 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
