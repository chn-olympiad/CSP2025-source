#include <bits/stdc++.h>
#define p 1000000007
#define K 131
using namespace std;

inline long long read(void) {
	long long x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - 48, c = getchar();
	return x * f;
}

inline void getstr (string &x) {
	x. clear();
	char c = getchar();
	while (c > 'z' || c < 'a') c = getchar();
	while (c >= 'a' && c <= 'z') x. push_back(c), c = getchar();
}

struct node {
	int x, y, id;
	friend bool operator< (node x, node y) {
		return x. x == y. x ? (x. y == y. y ? x. id < y. id : x. y < y. y) : x. x < y. x;
	}
};

vector<node> solve;

long long n, q, pw[5000005];
int nt[6000005][26], nt2[6000005][26], c[6000005], T, cnt, cnt2, cnt3, cnt4, fstq[200005], lstq[200005], fst[200005], lst[200005], dfn[6000005], dfn2[6000005], g[6000005], g2[6000005], sum[6000005], sum2[6000005], ans[200005];
map<pair<long long, long long>, long long> rt, rt2, updid, qryid;
vector<pair<int, int> > upd[2000005];
vector<int> query[2000005];
vector<int> nxt[6000005], nxt2[6000005];
string a[200005], b[200005], _ns[200005], _nt[200005];

void init (int x) {
	dfn[x] = ++T, g[x] = 1;
	for (auto i : nxt[x]) init(i), g[x] += g[i];
}

void init2 (int x) {
	dfn2[x] = ++T, g2[x] = 1;
	for (auto i : nxt2[x]) init2(i), g2[x] += g2[i];
}

void upd2 (int x, int y) {
	if (x > T) return;
	c[x] += y;
	upd2(x + (x & -x), y);
}

int query2 (int x) {
	if (!x) return 0;
	return c[x] + query2(x - (x & -x));
}

int main(void) {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read();
	pw[0] = 1;
	for (int i = 1; i <= 5000000; i++) pw[i] = pw[i - 1] * K % p;
	for (int i = 1; i <= n; i++) {
		getstr(a[i]), getstr(b[i]);
		int len = a[i]. size();
		fst[i] = -1, lst[i] = -1;
		long long sm = 0, sm2 = 0;
		for (int j = 0; j < len; j++) {
			if (a[i][j] == b[i][j]) continue;
			if (fst[i] == -1) fst[i] = j;
			lst[i] = j;
			(sm += a[i][j] * pw[j - fst[i]] % p) %= p;
			(sm2 += b[i][j] * pw[j - fst[i]] % p) %= p;
		}
		if (fst[i] == -1) continue;
		if (!rt[{sm, sm2}]) rt[{sm, sm2}] = ++cnt;
		if (!rt2[{sm, sm2}]) rt2[{sm, sm2}] = ++cnt2;
		long long w = rt[{sm, sm2}];
		for (int j = fst[i] - 1; j >= 0; j--) {
			if (!nt[w][a[i][j] - 'a']) nt[w][a[i][j] - 'a'] = ++cnt, nxt[w]. push_back(cnt);
			w = nt[w][a[i][j] - 'a'];
		}
		long long w2 = rt2[{sm, sm2}];
		for (int j = lst[i] + 1; j < len; j++) {
			if (!nt2[w2][a[i][j] - 'a']) nt2[w2][a[i][j] - 'a'] = ++cnt2, nxt2[w2]. push_back(cnt2);
			w2 = nt2[w2][a[i][j] - 'a'];
		}
		if (!updid[{sm, sm2}]) updid[{sm, sm2}] = ++cnt4;
		upd[updid[{sm, sm2}]]. push_back({w, w2});
	}
	for (int i = 1; i <= q; i++) {
		getstr(_ns[i]), getstr(_nt[i]);
		int len = _ns[i]. size();
		fstq[i] = lstq[i] = -1;
		long long sm = 0, sm2 = 0;
		for (int j = 0; j < len; j++) {
			if (_ns[i][j] == _nt[i][j]) continue;
			if (fstq[i] == -1) fstq[i] = j;
			lstq[i] = j;
			(sm += pw[j - fstq[i]] * _ns[i][j] % p) %= p;
			(sm2 += pw[j - fstq[i]] * _nt[i][j] % p) %= p;
		}
		if (rt[{sm, sm2}]) {
			if (!qryid[{sm, sm2}]) qryid[{sm, sm2}] = ++cnt3;
			query[qryid[{sm, sm2}]]. push_back(i);
		}
	}
	for (auto _i : rt) {
		long long i = _i. second, j = rt2[_i. first], k = qryid[_i. first], u = updid[_i. first];
		if (!k) continue;
		T = 0;
		init(i);
		T = 0;
		init2(j);
		solve. clear();
		for (auto _xx : upd[u]) {
			int xx = _xx. first, yy = _xx. second;
			solve. push_back({dfn[xx], dfn2[yy], 0});
			solve. push_back({dfn[xx] + g[xx], dfn2[yy], -2});
			solve. push_back({dfn[xx], dfn2[yy] + g2[yy], -2});
			solve. push_back({dfn[xx] + g[xx], dfn2[yy] + g2[yy], 0});
		}
		for (auto xx : query[k]) {
			long long w = i;
			for (int _ = fstq[xx] - 1; _ >= 0; _--) {
				if (!nt[w][_ns[xx][_] - 'a']) break;
				w = nt[w][_ns[xx][_] - 'a'];
			}
			long long w2 = j;
			for (int _ = lstq[xx] + 1; _ < _ns[xx]. size(); _++) {
				if (!nt2[w2][_ns[xx][_] - 'a']) break;
				w2 = nt2[w2][_ns[xx][_] - 'a'];
			}
			solve. push_back({dfn[w], dfn2[w2], xx});
		}
		sort(solve. begin(), solve. end());
		for (auto mygo : solve) {
			if (mygo. id > 0) ans[mygo. id] = query2(mygo. y);
			else upd2(mygo. y, mygo. id + 1);
		}
		for (auto mygo : solve) if (mygo. id <= 0) upd2(mygo. y, -mygo. id - 1);
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}
