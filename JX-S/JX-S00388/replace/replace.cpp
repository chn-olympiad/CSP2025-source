#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int L = 5e6 + 5;
int n, qq; char s[L], t[L], ins[L];
int ch[L][26], cnt, edc[L], fail[L], dep[L];
int rt[L], ans[N];
const int CT = 95000000;
int ls[CT], rs[CT], sum[CT];
// struct Tree { int l, r, s; }T[L * 23];
#define lp l, mid
#define rp mid + 1, r
inline void Update(int &k, int l, int r, int u, int v) {
	// T[++ cnt] = T[k]; k = cnt; T[k].s += v;
	++ cnt;
	ls[cnt] = ls[k], rs[cnt] = rs[k], sum[cnt] = sum[k] + v;
	k = cnt;
	if (l == r) return ;
	int mid = (l + r) >> 1;
	if (u <= mid) Update(ls[k], lp, u, v);
	else Update(rs[k], rp, u, v);
}
inline int Query(int k, int l, int r, int L) {
	if (!k || r < L) return 0;
	if (l >= L) return sum[k];
	int mid = (l + r) >> 1;
	if (L <= mid) return Query(ls[k], lp, L) + sum[rs[k]];
	else return Query(rs[k], rp, L);
}
vector <pair <int, int > > Q[L];
queue < int > q;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> qq; int mxd = 0;
	for (int i = 1, len; i <= n; ++ i) {
		cin >> s >> t; len = strlen(s);
		for (int j = 0; j < len; ++ j) ins[j << 1] = s[j], ins[j << 1 | 1] = t[j];
		int nw = 0;
		for (int j = 0; j < (len << 1); ++ j) {
			if (!ch[nw][ins[j] - 'a']) ch[nw][ins[j] - 'a'] = ++ cnt, dep[cnt] = dep[nw] + 1, mxd = max(mxd, dep[cnt]);
			nw = ch[nw][ins[j] - 'a'];
		} edc[nw] ++;
	}
	for (int i = 0; i < 26; ++ i) if (ch[0][i]) q.push(ch[0][i]);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; ++ i) {
			if (!ch[u][i]) ch[u][i] = ch[fail[u]][i];
			else fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
		}
	}
	for (int i = 1, len, tl; i <= qq; ++ i) {
		cin >> s >> t; len = strlen(s), tl = strlen(t);
		if (len != tl) continue;
		int st = -1, ed = -1;
		for (int j = 0; j < len; ++ j) {
			ins[j << 1] = s[j], ins[j << 1 | 1] = t[j];
			if (s[j] != t[j]) ed = j, st = st == -1 ? j : st;
		}
		st = st << 1, ed = ed << 1 | 1;
		int nw = 0;
		for (int j = 0; j < (len << 1); ++ j) {
			nw = ch[nw][ins[j] - 'a']; if (!(j & 1) || ed > j) continue;
			Q[nw].emplace_back(make_pair(j - st + 1, i));
		}
	}
	for (int i = 0; i < 26; ++ i) if (ch[0][i]) q.push(ch[0][i]);
	while (!q.empty()) {
		int u = q.front(); rt[u] = rt[fail[u]]; q.pop();
		if (edc[u]) Update(rt[u], 1, mxd, dep[u], edc[u]);
		for (auto ques : Q[u]) ans[ques.second] += Query(rt[u], 1, mxd, ques.first);
		for (int i = 0; i < 26; ++ i) if (dep[ch[u][i]] == dep[u] + 1) q.push(ch[u][i]);
	}
	for (int i = 1; i <= qq; ++ i) cout << ans[i] << '\n';
}