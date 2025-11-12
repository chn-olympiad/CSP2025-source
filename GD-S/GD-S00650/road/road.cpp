#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
long long min(const long long a, const long long b) {
	return a < b ? a : b;
}
__uint128_t min1(const __uint128_t a, const __uint128_t b) {
	return a < b ? a : b;
}
typedef struct {
	int from, to, nxt, id;
	long long val;
} Edge;
Edge e[4000001], tmp[4000001];
int n, m, k, u, v, cnt, p1, p2, fa[30001], siz[30001], pcnt, mnp[30001][11], us[11], stat[11], cnt1;
long long c[11], w;
__uint128_t ans = 1e19;
void add(const int from, const int to, const long long val, const int id) {
	e[++cnt].from = from;
	e[cnt].to = to;
	e[cnt].val = val;
	e[cnt].id = id;
}
void read(int *x) {
	*x = 0;
	int f = 1, ch = getchar();
	while (!isdigit(ch)) {
		if (ch == 45) {
			f = -f;
		}
		ch = getchar();
	}
	do {
		*x = (*x << 1) + (*x << 3) + (ch ^ 48);
		ch = getchar();
	} while (isdigit(ch));
	*x *= f;
}
void readL(long long *x) {
	*x = 0;
	int f = 1, ch = getchar();
	while (!isdigit(ch)) {
		if (ch == 45) {
			f = -f;
		}
		ch = getchar();
	}
	do {
		*x = (*x << 1ll) + (*x << 3ll) + (ch ^ 48);
		ch = getchar();
	} while (isdigit(ch));
	*x *= f;
}
void write(__uint128_t x) {
	if (x > 9ull) {
		write(x / 10ull);
	}
	putchar(((int) (x % 10ull)) + 48);
}
int cmp(const void *a, const void *b) {
	Edge *ea = (Edge *) a, *eb = (Edge *) b;
	return ea -> val > eb -> val ? 1 : -1;
}
int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}
void dfs(int x) {
	if (x > k) {
		cnt = cnt1;
		pcnt = 0;
		__uint128_t tot = 0, tot1 = 0;
		for (int i = 1; i <= cnt1; ++i) {
			e[i] = tmp[i];
		}
		long long x[10001];
		for (int i = 1; i <= n + 1; ++i) {
			fa[i] = i;
			siz[i] = 1;
			x[i] = 2147483648ll;
		}
		for (int i = 1; i <= k; ++i) {
			if (stat[i]) {
				tot += c[i];
				tot1 += c[i];
				for (int j = 1; j <= n; ++j) {
					x[j] = min(mnp[j][i], x[j]);
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			add(i, n + 1, x[i], i);
			add(n + 1, i, x[i], i);
		}
		qsort(e + 1, cnt, sizeof(Edge), cmp);
		for (int i = 1; i <= cnt; ++i) {
			int ssu = e[i].from, ssv = e[i].to;
			long long mn = e[i].val;
			u = find(ssu);
			v = find(ssv);
			if (u == v) {
				continue;
			}
			if (siz[u] > siz[v]) {
				fa[u] = v;
				siz[v] += siz[u];
			}
			else {
				fa[v] = u;
				siz[u] += siz[v];
			}
			tot += mn;
			if (ssv && ssv <= n + 1) {
				++pcnt;
			}
			if (pcnt == n || tot1 == 0 && pcnt == n - 1) {
				break;
			}
		}
		ans = min1(tot, ans);
		return;
	}
	stat[x] = 0;
	dfs(x + 1);
	stat[x] = 1;
	dfs(x + 1);
	stat[x] = 0;
}
int main() {
	#ifndef FKZLOVESDEBUG
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	#endif
	read(&n);
	read(&m);
	read(&k);
	for (int i = 0; i < m; ++i) {
		read(&u);
		read(&v);
		readL(&w);
		add(u, v, w, 0);
		add(v, u, w, 0);
	}
	if (k == 0) {
		ans = 0;
		for (int i = 1; i <= n + 1; ++i) {
			fa[i] = i;
			siz[i] = 1;
		}
		qsort(e + 1, cnt, sizeof(Edge), cmp);
		for (int i = 1; i <= cnt; ++i) {
			int ssu = e[i].from, ssv = e[i].to;
			long long mn = e[i].val;
			u = find(ssu);
			v = find(ssv);
			if (u == v) {
				continue;
			}
			if (siz[u] > siz[v]) {
				fa[u] = v;
				siz[v] += siz[u];
			}
			else {
				fa[v] = u;
				siz[u] += siz[v];
			}
			ans += mn;
			if (ssv <= n) {
				++pcnt;
			}
			if (pcnt == n - 1) {
				break;
			}
		}
		write(ans);
		return 0;
	}
	cnt1 = cnt;
	for (int i = 1; i <= cnt; ++i) {
		tmp[i] = e[i];
	}
	for (int j = 1; j <= k; ++j) {
		readL(&c[j]);
		for (int i = 1; i <= n; ++i) {
			readL(&w);
			mnp[i][j] = w;
		}
	}
	dfs(1);
	write(ans);
}
