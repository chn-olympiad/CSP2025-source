#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;

char buf[1 << 25], *S, *T;
char gc() {return S == T && (T = (S = buf) + fread(buf, 1, 1 << 25, stdin)) == buf ? 0 : *S++;}
int read() {
	char ch; while ((ch = gc()) <= ' '); int x = ch - '0';
	while ((ch = gc()) > ' ') x = 10 * x + ch - '0'; return x;
}
void read(char *str) {
	char ch; while ((ch = gc()) <= ' '); *str++ = ch;
	while ((ch = gc()) > ' ') *str++ = ch;
	*str = 0;
}

const int MAXS = 5000005 + 2 * MAXN;
char s[MAXS], t[MAXS];
int trie[MAXS][26], cnt; int lnode[MAXS], rnode[MAXS], dfn[MAXS], low[MAXS], head[MAXS];
int lnk[MAXN * 2], to[MAXN * 2], typ[MAXN * 2], lcnt; int qans[MAXN];

void add(int u, int v, int w) {
	lcnt++; lnk[lcnt] = head[u]; to[lcnt] = v; typ[lcnt] = w; head[u] = lcnt;
}

namespace fenw {
	int c[MAXS]; void modify(int u, int w) {for (; u < MAXS; u += u & -u) c[u] += w;}
	int query(int u) {int w = 0; for (; u; u -= u & -u) w += c[u]; return w;}
}


int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n = read(), q = read();
	cnt++; vector<pair<int, int>> hihi;
	for (int i = 1; i <= n; i++) {
		read(s); read(t); int x = strlen(s);
		int lp = 0; while (lp < x && s[lp] == t[lp]) lp++;
		if (lp == x) continue;
		int rp = 0; while (s[x - rp - 1] == t[x - rp - 1]) rp++;
		
		int crt = 1;
		for (int i = lp; i < x - rp; i++) {
			if (trie[crt][s[i] - 'a'] == 0) trie[crt][s[i] - 'a'] = ++cnt;
			crt = trie[crt][s[i] - 'a'];
		}
		for (int i = lp; i < x - rp; i++) {
			if (trie[crt][t[i] - 'a'] == 0) trie[crt][t[i] - 'a'] = ++cnt;
			crt = trie[crt][t[i] - 'a'];
		}
		if (lnode[crt] == 0) lnode[crt] = ++cnt, rnode[crt] = ++cnt;
		
		int lrt = lnode[crt];
		for (int i = lp - 1; ~i; i--) {
			if (trie[lrt][s[i] - 'a'] == 0) trie[lrt][s[i] - 'a'] = ++cnt;
			lrt = trie[lrt][s[i] - 'a'];
		}

		int rrt = rnode[crt];
		for (int i = x - rp; i < x; i++) {
			if (trie[rrt][s[i] - 'a'] == 0) trie[rrt][s[i] - 'a'] = ++cnt;
			rrt = trie[rrt][s[i] - 'a'];
		}
		add(lrt, rrt, 0);
	}
	for (int i = 1; i <= q; i++) {
		read(s); read(t); int x = strlen(s), y = strlen(t);
		if (x != y) continue;
		
		int lp = 0; while (s[lp] == t[lp]) lp++;
		int rp = 0; while (s[x - rp - 1] == t[x - rp - 1]) rp++;

		
		int crt = 1;
		for (int i = lp; i < x - rp; i++) crt = trie[crt][s[i] - 'a'];
		for (int i = lp; i < x - rp; i++) crt = trie[crt][t[i] - 'a'];
		if (lnode[crt] == 0) continue;

		int lrt = lnode[crt];
		for (int i = lp - 1; ~i; i--) {
			if (trie[lrt][s[i] - 'a'] == 0) break;
			lrt = trie[lrt][s[i] - 'a'];
		}

		int rrt = rnode[crt];
		for (int i = x - rp; i < x; i++) {
			if (trie[rrt][s[i] - 'a'] == 0) break;
			rrt = trie[rrt][s[i] - 'a'];
		}
		add(lrt, rrt, i);
	}

	// printf("lcnt %d\n", lcnt);
	// return 0;

	int times = 0;

	for (int _ = 0; _ < cnt; _++) if (lnode[_]) {
		vector<int> stk; stk.push_back(rnode[_]);
		while (stk.empty() == 0) {
			int u = stk.back(); stk.pop_back();
			if (u > 0) {
				dfn[u] = ++times; stk.push_back(-u);
				for (int _ = 0; _ < 26; _++) if (trie[u][_]) stk.push_back(trie[u][_]);
			}
			else {
				low[-u] = times;
			}
		}
		stk.push_back(lnode[_]);
		while (stk.empty() == 0) {
			int u = stk.back(); stk.pop_back();
			if (u > 0) {
				for (int i = head[u]; i; i = lnk[i]) {
					if (typ[i] == 0) fenw::modify(dfn[to[i]], 1), fenw::modify(low[to[i]] + 1, -1);
				}
				for (int i = head[u]; i; i = lnk[i]) {
					if (typ[i]) qans[typ[i]] = fenw::query(dfn[to[i]]);
				}
				stk.push_back(-u); for (int _ = 0; _ < 26; _++) if (trie[u][_]) stk.push_back(trie[u][_]);
			}
			else {
				u *= -1;
				for (int i = head[u]; i; i = lnk[i]) {
					if (typ[i] == 0) fenw::modify(dfn[to[i]], -1), fenw::modify(low[to[i]] + 1, 1);
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) printf("%d\n", qans[i]);
}
/*
run replace < replace1.in > replace1.out
run replace < replace2.in > replace2.out
run replace < replace3.in > replace3.out
run replace < replace4.in > replace4.out
diff replace1.out replace1.ans -Z
diff replace2.out replace2.ans -Z
diff replace3.out replace3.ans -Z
diff replace4.out replace4.ans -Z
*/
/*
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int a[MAXN], buc[1000005]; long long dp[MAXN];
vector<int> pls[MAXN];
int main() {
	int t; scanf("%d", &t); while (t--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), buc[a[i]] = 0, pls[i].clear();
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			if (buc[a[i]]) {
				if (buc[a[i]] == i - 1) sum += a[i];
				else pls[i].push_back(buc[a[i]] + 1);
			}
			buc[a[i]] = i;
		}
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1]; for (int j : pls[i]) dp[i] = max(dp[i], dp[j] + a[i]);
		}
		printf("%lld\n", sum + dp[n]);
	}
}

你什么 t3 我什么 t3 .jpg
*/