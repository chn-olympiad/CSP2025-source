#include <bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define mk make_pair
#define lowbit(x) (x & -x)
using namespace std;

const int N = 200010, M = 6e6 + 10, base = 131, mod = 1e9 + 7, mod2 = 1e9 + 9;
int n, m, pos[N], qpos[N], ans[N];
int tim, dfn[M], lst[M];
char s1[M], s2[M];
map<pii, pii> rt;
int tot, t[M][26];
vector<int> vec[M], qry[M];
pii getrt(pii x) {
	if (rt.find(x) != rt.end()) return rt[x];
	pii ret(tot + 1, tot + 2); tot += 2;
	return rt[x] = ret;
}

void insert(pii Rt, char s[], int pre, int suf, int len, int id) {
	int p = Rt.fir;
	for (int i=suf+1; i<=len; ++i) {
		int c = s[i] - 'a';
		if (!t[p][c]) t[p][c] = ++tot;
		p = t[p][c];
	}
	vec[p].push_back(id);
	p = Rt.sec;
	for (int i=pre-1; i; --i) {
		int c = s[i] - 'a';
		if (!t[p][c]) t[p][c] = ++tot;
		p = t[p][c];
	}
	pos[id] = p;
}
void query(pii Rt, char s[], int pre, int suf, int len, int id) {
	int p = Rt.fir;
	for (int i=suf+1; i<=len; ++i) {
		int c = s[i] - 'a';
		if (!t[p][c]) break;
		p = t[p][c];
	}
	qry[p].push_back(id);
	p = Rt.sec;
	for (int i=pre-1; i; --i) {
		int c = s[i] - 'a';
		if (!t[p][c]) break;
		p = t[p][c];
	}
	qpos[id] = p;
}

void dfs(int x) {
	dfn[x] = ++tim;
	for (int i=0; i<26; ++i)
		if (t[x][i]) dfs(t[x][i]);
	lst[x] = tim;
}

int bit[M];
void change(int x, int k) {
	for (; x<=tim; x+=lowbit(x)) bit[x] += k;
}
void change(int l, int r, int k) {
	change(l, k), change(r + 1, -k);
}
int query(int x) {
	int ret = 0;
	for (; x; x-=lowbit(x)) ret += bit[x];
	return ret;
}

void getans(int x) {
	for (auto id : vec[x]) {
		int y = pos[id];
		change(dfn[y], lst[y], 1);
	}
	for (auto id : qry[x]) {
		int y = qpos[id];
		ans[id] = query(dfn[y]);
	}
	for (int i=0; i<26; ++i)
		if (t[x][i]) getans(t[x][i]);
	for (auto id : vec[x]) {
		int y = pos[id];
		change(dfn[y], lst[y], -1);
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i) {
		scanf("%s%s", s1 + 1, s2 + 1);
		int len = strlen(s1 + 1);
		int pre = len + 1, suf = 0;
		for (int j=1; j<=len; ++j)
			if (s1[j] != s2[j]) {
				suf = j;
				if (pre > j) pre = j;
			}
		if (pre > suf) continue;
		int h1 = 0, h2 = 0;
		for (int j=pre; j<=suf; ++j) {
			h1 = (1ll * h1 * base + s1[j]) % mod;
			h2 = (1ll * h2 * base + s1[j]) % mod2;
		}
		for (int j=pre; j<=suf; ++j) {
			h1 = (1ll * h1 * base + s2[j]) % mod;
			h2 = (1ll * h2 * base + s2[j]) % mod2;
		}
		pii p = getrt(mk(h1, h2));
		insert(p, s1, pre, suf, len, i);
	}
	for (int i=1; i<=m; ++i) {
		scanf("%s%s", s1 + 1, s2 + 1);
		int len = strlen(s1 + 1);
		if (len != strlen(s2 + 1)) continue;
		int pre = len + 1, suf = 0;
		for (int j=1; j<=len; ++j)
			if (s1[j] != s2[j]) {
				suf = j;
				if (pre > j) pre = j;
			}
		if (pre > suf) continue;
		int h1 = 0, h2 = 0;
		for (int j=pre; j<=suf; ++j) {
			h1 = (1ll * h1 * base + s1[j]) % mod;
			h2 = (1ll * h2 * base + s1[j]) % mod2;
		}
		for (int j=pre; j<=suf; ++j) {
			h1 = (1ll * h1 * base + s2[j]) % mod;
			h2 = (1ll * h2 * base + s2[j]) % mod2;
		}
		if (rt.find(mk(h1, h2)) == rt.end()) continue;
		pii p = rt[mk(h1, h2)];
		query(p, s1, pre, suf, len, i);
	}
	for (auto i : rt) {
		tim = 0, dfs(i.sec.sec);
		getans(i.sec.fir);
	}
	for (int i=1; i<=m; ++i) printf("%d\n", ans[i]);
	return 0;
}