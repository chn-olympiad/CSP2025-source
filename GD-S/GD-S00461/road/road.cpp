#include <bits/stdc++.h>

using namespace std;

int read() {
	int s = 0, f = 1;
	char c = getchar();
	while (! isdigit(c)) {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (isdigit(c)) {
		s = (s << 1) + (s << 3) + c - 48;
		c = getchar(); 
	}
	return s * f;
}
void write(long long x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x + 48);
	} else {
		write(x / 10);
		putchar(x % 10 + 48);
	}
}

struct edge {
	int x, y, z;
	bool operator < (const edge & t) const {
		return z > t.z;
	}
};

int n, m, k;
int c[17], a[17][10007];
int fa[10027];
long long ans = LLONG_MAX;

inline int find(int x) {
	return (fa[x] == x ? x : (fa[x] = find(fa[x])));
}
inline long long kruskal(int p, priority_queue < edge > pq) {
	long long res = 0;
	int cnt = 0, xc = 0;
	for (int i = 0; i < k; ++ i) {
		if ((p >> i) & 1) {
			++ xc;
			res += c[i + 1];
			for (int j = 1; j <= n; ++ j) {
				pq.push({n + xc, j, a[i + 1][j]});
			}
		}
	}
	iota(fa + 1, fa + 1 + n + xc, 1);
	while (! pq.empty()) {
		edge t = pq.top();
		pq.pop();
		int x = find(t.x);
		int y = find(t.y);
		if (x != y) {
			fa[y] = x;
			res += t.z;
			++ cnt;
			if (cnt == n + xc - 1) {
				return res;
			}
		}
	}
	return LLONG_MAX;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	priority_queue < edge > pq;
	for (int i = 1; i <= m; ++ i) {
		int x = read(), y = read(), z = read();
		pq.push({x, y, z});
	}
	for (int i = 1; i <= k; ++ i) {
		c[i] = read();
		for (int j = 1; j <= n; ++ j) {
			a[i][j] = read();
		}
	}
	for (int i = 0; i < (1 << k); ++ i) {
		ans = min(ans, kruskal(i, pq));
	}
	write(ans);
	puts("");
	return 0;
}
