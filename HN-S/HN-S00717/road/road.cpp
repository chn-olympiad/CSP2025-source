#include <cstdio>
#include <vector>

struct roadIfm {
	int u, v, w;
};

inline void read(int &goal) {
	int x = 0;
	char c = getchar();
	while (c > 57 || c < 48) c = getchar();
	while (c > 47 && c < 58) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	goal = x;
}
inline void write(int n) {
	char buffer[10], *pos = buffer;
	do *pos++ = n % 10 + 48; while (n /= 10);
	do putchar(*--pos); while (pos > buffer);
}

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	int n, m, k; read(n); read(m); read(k);
	int *c = new int[k];
	vector<vector<int>> p(k, vector<int>(n));
	roadIfm *r = new roadIfm[m];
	for (int i = 0; i < m; i++) {
		read(r[i].u); read(r[i].v); read(r[i].w);
	}
	for (int i = 0; i < k; i++) {
		read(c[i]);
		for (int j = 0; j < n; j++) read(p[i][j]);
	}
	return 0;
}
