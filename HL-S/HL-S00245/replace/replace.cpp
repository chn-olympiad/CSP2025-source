// Understand Nailoong
#include <bits/stdc++.h>
#define fin(x) freopen(#x ".in", "r", stdin);
#define fout(x) freopen(#x ".out", "w", stdout);
#define file(x) fin(x); fout(x);
using namespace std;
constexpr int N = 2e5 + 5;
constexpr int M = 1e7 + 5;
int n, m, cnt, idx, sl[N], sr[N], tl[N], tr[N], ans[N];
string s[N][2], t[N][2];
struct Node{ int son[27], val, fail; } tree[M];
vector <int> S[N << 1], T[N << 1];
queue <int> q;
signed main() {
	cin.tie(0) -> sync_with_stdio(false);
	file(replace);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i][0] >> s[i][1];
		int len = s[i][0].length();
		for (int j = len - 1; ~j; --j) if (s[i][0][j] != s[i][1][j]) sl[i] = j;
		for (int j = 0; j < len; ++j) if (s[i][0][j] != s[i][1][j]) sr[i] = j;
		int now = 0;
		for (int j = sl[i]; j <= sr[i]; ++j) {
			if (!tree[now].son[s[i][0][j] - 'a']) tree[now].son[s[i][0][j] - 'a'] = ++idx;
			now = tree[now].son[s[i][0][j] - 'a'];
			if (!tree[now].son[s[i][1][j] - 'a']) tree[now].son[s[i][1][j] - 'a'] = ++idx;
			now = tree[now].son[s[i][1][j] - 'a'];
		}
		if (!tree[now].val) tree[now].val = ++cnt;
		S[tree[now].val].emplace_back(i);
	}
	for (int i = 1; i <= m; ++i) {
		cin >> t[i][0] >> t[i][1];
		int len = t[i][0].length();
		for (int j = len - 1; ~j; --j) if (t[i][0][j] != t[i][1][j]) tl[i] = j;
		for (int j = 0; j < len; ++j) if (t[i][0][j] != t[i][1][j]) tr[i] = j;
		int now = 0;
		for (int j = tl[i]; j <= tr[i]; ++j) {
			if (!tree[now].son[t[i][0][j] - 'a']) tree[now].son[t[i][0][j] - 'a'] = ++idx;
			now = tree[now].son[t[i][0][j] - 'a'];
			if (!tree[now].son[t[i][1][j] - 'a']) tree[now].son[t[i][1][j] - 'a'] = ++idx;
			now = tree[now].son[t[i][1][j] - 'a'];
		}
		if (!tree[now].val) tree[now].val = ++cnt;
		T[tree[now].val].emplace_back(i);
	}
	for (int p = 1; p <= cnt; ++p) {
		if (S[p].empty() || T[p].empty()) continue;
		for (int i = 0; i <= idx; ++i) {
			for (int j = 0; j < 27; ++j) tree[i].son[j] = 0;
			tree[i].val = tree[i].fail = 0;
		}
		idx = 0;
		for (auto i : S[p]) {
			int now = 0;
			for (int j = 0; j < sl[i]; ++j) {
				if (!tree[now].son[s[i][0][j] - 'a']) tree[now].son[s[i][0][j] - 'a'] = ++idx;
				now = tree[now].son[s[i][0][j] - 'a'];
			}
			if (!tree[now].son[26]) tree[now].son[26] = ++idx;
			now = tree[now].son[26];
			for (int j = sr[i] + 1; j < s[i][0].length(); ++j) {
				if (!tree[now].son[s[i][0][j] - 'a']) tree[now].son[s[i][0][j] - 'a'] = ++idx;
				now = tree[now].son[s[i][0][j] - 'a'];
			}
			++tree[now].val;
		}
		
		for (int i = 0; i <= 26; ++i) if (tree[0].son[i]) tree[tree[0].son[i]].fail = 0, q.push(tree[0].son[i]);
		while(q.size()) {
			int x = q.front(); q.pop();
			for (int i = 0; i <= 26; ++i) {
				if (tree[x].son[i]) tree[tree[x].son[i]].fail = tree[tree[x].fail].son[i], tree[tree[x].son[i]].val += tree[tree[tree[x].fail].son[i]].val, q.push(tree[x].son[i]);
				else tree[x].son[i] = tree[tree[x].fail].son[i];
			}
		}
		for (auto i : T[p]) {
			int now = 0;
			for (int j = 0; j < tl[i]; ++j) now = tree[now].son[t[i][0][j] - 'a'];
			now = tree[now].son[26], ans[i] += tree[now].val;
			for (int j = tr[i] + 1; j < t[i][0].length(); ++j) now = tree[now].son[t[i][0][j] - 'a'], ans[i] += tree[now].val;
		}
	}
	for (int i = 1; i <= m; ++i) cout << ans[i] << '\n';
}