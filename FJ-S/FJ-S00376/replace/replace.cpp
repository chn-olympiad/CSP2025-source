#include <bits/stdc++.h>
typedef long long ll;
const int L = 5e6 + 5;
const int N = 2e5 + 5; 
const ll B1 = 31;
const ll mod1 = 1e9 + 7;
const ll B2 = 131;
const ll mod2 = 998244353;

int n, q, cnt, b1[L], b2[L], ans[N];
ll h1[L], h2[L], h3[L], h4[L];
char str[L * 3];
struct Node { ll h1, h2, h3, h4; char *s, *t; int l, r, len, id; } num[N << 1];
struct Que { int l, r, x, id; } Q[N << 1], Q2[N << 2]; 

int tr[L << 1][26], cnt1, cnt2;
std::vector<int> e1[L << 1], e2[L << 1]; 

ll calc1(ll *a, int l, int r) {
	if (r == 0) return 0;
	return (a[r] - a[l - 1] * b1[r - l + 1] % mod1 + mod1) % mod1;
} 
 
ll calc2(ll *a, int l, int r) {
	return (a[r] - a[l - 1] * b2[r - l + 1] % mod2 + mod2) % mod2;
} 

int dfn1[L << 1], rdfn1[L << 1], dfn2[L << 1], rdfn2[L << 1], tot;

void dfs1(int u) {
	dfn1[u] = ++tot;
	for (int v : e1[u]) dfs1(v);
	rdfn1[u] = tot;
}

void dfs2(int u) {
	dfn2[u] = ++tot;
	for (int v : e2[u]) dfs2(v);
	rdfn2[u] = tot;
}

int sum[L << 1], res;
void add(int x, int k) { for (; x <= cnt2; x += x & -x) sum[x] += k; }
int ask(int x) { for (res = 0; x; x ^= x & -x) res += sum[x]; return res; }
void update(int x, int y, int k) { add(x, k); add(y + 1, -k); }
int query(int x) { return ask(x); }

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	b1[0] = b2[0] = 1;
	for (int i = 1; i < L; ++i) b1[i] = b1[i - 1] * B1 % mod1, b2[i] = b2[i - 1] * B2 % mod2;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n + q; ++i) {
		int l = 1e9, r = 0; 
		num[i].s = str + cnt;
		scanf("%s", num[i].s + 1); 
		int len = strlen(num[i].s + 1);
		cnt += len + 2;
		
		num[i].t = str + cnt;
		scanf("%s", num[i].t + 1); 
		cnt += len + 2;
		
		for (int j = 1; j <= len; ++j) {
			if (num[i].s[j] ^ num[i].t[j]) (!r ? (l = j) : 0), r = j; 
			h1[j] = (h1[j - 1] * B1 + (num[i].s[j] - 'a' + 1)) % mod1;
			h2[j] = (h2[j - 1] * B2 + (num[i].s[j] - 'a' + 1)) % mod2;
			h3[j] = (h3[j - 1] * B1 + (num[i].t[j] - 'a' + 1)) % mod1;
			h4[j] = (h4[j - 1] * B2 + (num[i].t[j] - 'a' + 1)) % mod2;
		}
		
		if (!r) continue;
		
		num[i].l = l; num[i].r = r; num[i].len = len;
		
		num[i].h1 = calc1(h1, l, r);
		num[i].h2 = calc2(h2, l, r);
		num[i].h3 = calc1(h3, l, r);
		num[i].h4 = calc2(h4, l, r);
		
		if (i > n) num[i].id = i - n; 
	}
	
	std::sort(num + 1, num + 1 + n + q, [](Node a, Node b){ 
		if (a.h1 != b.h1) return a.h1 < b.h1;
		if (a.h2 != b.h2) return a.h2 < b.h2;
		if (a.h3 != b.h3) return a.h3 < b.h3;
		if (a.h4 != b.h4) return a.h4 < b.h4;
		return a.id < b.id;
	});
	
	
	for (int l = 1, r = l; l <= n + q; l = r + 1, r = l) {
		while (r < n + q && num[r + 1].h1 == num[l].h1 && num[r + 1].h2 == num[l].h2
			&& num[r + 1].h3 == num[l].h3 && num[r + 1].h4 == num[l].h4) ++r;
			
		std::vector<std::pair<int, int>> v1, v2;
		cnt1 = cnt2 = 1; e1[1].clear(); e2[1].clear(); int m = 0;
		
//		for (int i = l; i <= r; ++i)
//			printf("%s %s %d %d %d %d\n", num[i].s + 1, num[i].t + 1, num[i].l, num[i].r, num[i].len, num[i].id);
//		puts("");
		
		for (int i = l; i <= r; ++i) {
			int p = 1; Q[++m].id = num[i].id;
			for (int j = num[i].r + 1; j <= num[i].len; ++j) {
				if (!tr[p][num[i].s[j] - 'a']) tr[p][num[i].s[j] - 'a'] = ++cnt1, v1.push_back({p, num[i].s[j] - 'a'}), e1[p].push_back(cnt1), e1[cnt1].clear();
				p = tr[p][num[i].s[j] - 'a'];
			} Q[m].l = p; p = 1;
		}
		tot = 0; dfs1(1); tot = 0;
		
		for (int i = 1; i <= m; ++i) {
//			printf("%d %d %d\n", Q[i].l, Q[i].r, Q[i].id);
			if (!Q[i].id) { 
				Q2[++tot] = {dfn2[Q[i].r], rdfn2[Q[i].r], dfn1[Q[i].l], 0};
				Q2[++tot] = {dfn2[Q[i].r], rdfn2[Q[i].r], rdfn1[Q[i].l] + 1, -1};
			} else {
				Q2[++tot] = {dfn2[Q[i].r], 0, dfn1[Q[i].l], Q[i].id};
			}
		}//puts("");
		
//		for (int i = 1; i <= tot; ++i) {
//			printf("%d %d %d %d\n", Q2[i].x, Q2[i].l, Q2[i].r, Q2[i].id);
//		}
		for (auto x : v1) tr[x.first][x.second] = 0;
		
		m = 0;
		
//		for (int i = l; i <= r; ++i)
//			printf("%s %s %d %d %d %d\n", num[i].s + 1, num[i].t + 1, num[i].l, num[i].r, num[i].len, num[i].id);
//		puts("");
		
		for (int i = l; i <= r; ++i) {
			int p = 1; Q[++m].id = num[i].id;
			for (int j = num[i].l - 1; j >= 1; --j) {
				if (!tr[p][num[i].s[j] - 'a']) tr[p][num[i].s[j] - 'a'] = ++cnt2, v2.push_back({p, num[i].s[j] - 'a'}), e2[p].push_back(cnt2), e2[cnt2].clear();
				p = tr[p][num[i].s[j] - 'a'];
			} Q[m].r = p; p = 1;
		}
		
		tot = 0; dfs2(1); tot = 0;
		
		for (int i = 1; i <= m; ++i) {
//			printf("%d %d %d\n", Q[i].l, Q[i].r, Q[i].id);
			if (!Q[i].id) { 
				Q2[++tot].l = dfn2[Q[i].r]; Q2[tot].r = rdfn2[Q[i].r];
				Q2[++tot].l = dfn2[Q[i].r]; Q2[tot].r = rdfn2[Q[i].r];
			} else {
				Q2[++tot].l = dfn2[Q[i].r];
			}
		}//puts("");
		
		std::sort(Q2 + 1, Q2 + 1 + tot, [](Que a, Que b){ return a.x ^ b.x ? a.x < b.x : a.id < b.id; });
		for (int i = 1; i <= tot; ++i) {
			if (Q2[i].id > 0) {
				ans[Q2[i].id] = query(Q2[i].l);
			} else {
				update(Q2[i].l, Q2[i].r, !Q2[i].id ? 1 : -1);
			}
		}
		
		for (auto x : v2) tr[x.first][x.second] = 0; 
		// clear
	}
	
	for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]); 
	
	return 0;
}
