#include <cstdio>
#include <algorithm>
#include <cstring>
#define fi first
#define se second

typedef std::pair<int, int> pii;
typedef __int128 lll;
typedef long long ll;
const ll mod = 1000000000000000000ll + 3, seed = 19260817;
char s1[5000005], s2[5000005];
int n, q, tot, p1[200005], p2[200005], dfn[3000005], out[3000005], timer, rtcnt;
int ans[200005], ch[3000005][27], num;
pii allrt[200005];
struct node {
	int x, y, f, id;
	inline bool operator < (const node &rhs) const {return x ^ rhs.x ? x < rhs.x : id < rhs.id;}
} qst[2000005];
struct Hash_table {
	struct node {ll h1, h2; int id1, id2, nxt;} e[400005];
	static const int mod = 1 << 21;
	int head[mod + 5], tot;
	void add(ll h1, ll h2, int id1, int id2) {
		int u = ((lll)seed * h1 + (lll)h2) % mod;
		e[++ tot].h1 = h1, e[tot].h2 = h2, e[tot].id1 = id1, e[tot].id2 = id2;
		e[tot].nxt = head[u], head[u] = tot;
	}
	pii qry(ll h1, ll h2) {
		int u = ((lll)seed * h1 + (lll)h2) % mod;
		for (int i = head[u]; i; i = e[i].nxt)
			if (e[i].h1 == h1 && e[i].h2 == h2) return pii{e[i].id1, e[i].id2};
		return pii{-1, -1};
	}
} tab;
void init(char *s, int len) {for (int i = 1; i <= len; ++ i) s[i] -= 'a' - 1;}
void dfs(int u) {
	dfn[u] = ++ timer;
	for (int i = 1; i <= 26; ++ i) if (ch[u][i]) dfs(ch[u][i]);
	out[u] = timer;
}
void addrect(int x1, int x2, int y1, int y2) {
	qst[++ num] = node{x1, y1, 1, 0};
	if (x2 < tot) qst[++ num] = node{x2 + 1, y1, -1, 0};
	if (y2 < tot) qst[++ num] = node{x1, y2 + 1, -1, 0};
	if (x2 < tot && y2 < tot) qst[++ num] = node{x2 + 1, y2 + 1, 1, 0};
}
struct BIT {
	int c[2500005];
	inline void add(int x, int y) {for (int i = x; i <= tot; i += (i & -i)) c[i] += y;}
	inline int qry(int x) {int s = 0; for (int i = x; i; i &= i - 1) s += c[i]; return s;}
} bit;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++ i) {
		scanf("%s%s", s1 + 1, s2 + 1);
		int len = strlen(s1 + 1), st = 1, ed = len;
		init(s1, len), init(s2, len);
		while (st < len && s1[st] == s2[st]) ++ st;
		while (ed > 1 && s1[ed] == s2[ed]) -- ed;
		if (ed == 1 && s1[1] == s2[1]) continue;
		ll h1 = 0, h2 = 0;
		for (int j = st; j <= ed; ++ j)
			h1 = ((lll)h1 * seed + s1[j]) % mod, h2 = ((lll)h2 * seed + s2[j]) % mod;
		pii rt = tab.qry(h1, h2);
		if (rt.fi == -1) tab.add(h1, h2, rt.fi = tot + 1, rt.se = tot + 2), tot += 2, allrt[++ rtcnt] = rt;
		p1[i] = rt.fi;
		for (int j = st - 1; j; -- j) {
			if (!ch[p1[i]][s1[j]]) ch[p1[i]][s1[j]] = ++ tot;
			p1[i] = ch[p1[i]][s1[j]];
		}
		p2[i] = rt.se;
		for (int j = ed + 1; j <= len; ++ j) {
			if (!ch[p2[i]][s1[j]]) ch[p2[i]][s1[j]] = ++ tot;
			p2[i] = ch[p2[i]][s1[j]];
		}
	}
	for (int i = 1; i <= rtcnt; ++ i) dfs(allrt[i].fi), dfs(allrt[i].se);
	for (int i = 1; i <= n; ++ i) if (p1[i]) addrect(dfn[p1[i]], out[p1[i]], dfn[p2[i]], out[p2[i]]);
	for (int i = 1; i <= q; ++ i) {
		scanf("%s%s", s1 + 1, s2 + 1);
		int len = strlen(s1 + 1), st = 1, ed = len;
		if ((int)strlen(s2 + 1) != len) continue;
		init(s1, len), init(s2, len);
		while (st < len && s1[st] == s2[st]) ++ st;
		while (ed > 1 && s1[ed] == s2[ed]) -- ed;
		ll h1 = 0, h2 = 0;
		for (int j = st; j <= ed; ++ j)
			h1 = ((lll)h1 * seed + s1[j]) % mod, h2 = ((lll)h2 * seed + s2[j]) % mod;
		pii rt = tab.qry(h1, h2);
		if (rt.fi == -1) continue;
		int p1 = rt.fi, p2 = rt.se;
		for (int j = st - 1; j; -- j)
			if (!ch[p1][s1[j]]) break; else p1 = ch[p1][s1[j]];
		for (int j = ed + 1; j <= len; ++ j)
			if (!ch[p2][s1[j]]) break; else p2 = ch[p2][s1[j]];
		qst[++ num] = node{dfn[p1], dfn[p2], 0, i};
	}
	std::sort(qst + 1, qst + num + 1);
	for (int i = 1; i <= num; ++ i)
		if (!qst[i].id) bit.add(qst[i].y, qst[i].f);
		else ans[qst[i].id] = bit.qry(qst[i].y);
	for (int i = 1; i <= q; ++ i) printf("%d\n", ans[i]);
	return 0;
}
