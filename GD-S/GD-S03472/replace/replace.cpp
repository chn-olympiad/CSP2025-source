#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

struct Trienode
{
	int id = 0; //
	int son[26];
};

constexpr int N = 200010;
constexpr int L = 5000010;
int n;
int q;
std::string s[2][N];
std::string t[2][N];
int slen[N];
int tlen[N];
int sl[N];
int sr[N];
int tl[N];
int tr[N];
int nodecnt = 1;
Trienode trie[L * 2 + N];
std::vector<char> sonchar[L * 2 + N];
int nxt[N*2];
int ans[N];
int headcnt = 0;
int head[N];

int nxt2[N*3];
int ordercnt;
int order[N * 3];

int trie_insert(int i, std::string &s, const int l, const int r)
{
	for (int j = l; j <= r; ++j) {
		if (!trie[i].son[s[j] - 'a']) {
			++nodecnt;
			trie[i].son[s[j] - 'a'] = nodecnt;
			sonchar[i].push_back(s[j] - 'a');
		}
		i = trie[i].son[s[j] - 'a'];
	}
	return i;
}

int trie_insert_reverse(int i, std::string &s, const int r)
{
	for (int j = r; j >= 0; --j) {
		if (!trie[i].son[s[j] - 'a']) {
			++nodecnt;
			trie[i].son[s[j] - 'a'] = nodecnt;
			sonchar[i].push_back(s[j] - 'a');
		}
		i = trie[i].son[s[j] - 'a'];
	}
	return i;
}

int trie_query(int i, std::string &s, const int l, const int r)
{
	for (int j = l; i && j <= r; ++j)
		i = trie[i].son[s[j] - 'a'];
	return i;
}

void trie_trie_clear(const int i)
{
	if (trie[i].id < 0)
		trie_trie_clear(-trie[i].id);
	if (trie[i].id > 0) {
		++headcnt;
		head[headcnt] = trie[i].id;
	}
	trie[i].id = 0;
	for (const char c:sonchar[i]) {
		trie_trie_clear(trie[i].son[c]);
		trie[i].son[c] = 0;
	}
	sonchar[i].clear();
	sonchar[i].shrink_to_fit();
}

void trie_clear1(const int i)
{
	if (trie[i].id) {
		++ordercnt;
//		std::cerr << ordercnt << ':';
		for (int j = trie[i].id; j; j = nxt2[j]) {
//			std::cerr << ' ' << j;
			order[j] = ordercnt;
		}
		trie[i].id = 0;
//		std::cerr << '\n';
	}
	for (const char c:sonchar[i]) {
		trie_clear1(trie[i].son[c]);
		trie[i].son[c] = 0;
	}
	sonchar[i].clear();
	sonchar[i].shrink_to_fit();
}

int bit[N * 3];

void add(int i, const int x)
{
	for (; i <= ordercnt; i += i&-i)
		bit[i] += x;
}

int query(int i)
{
	int res = 0;
	for (; i; i -= i&-i)
		res += bit[i];
	return res;
}

void trie_clear2(const int i)
{
//	std::cerr << "enter " << i << '\n';
	for (int j = trie[i].id; j; j = nxt2[j]) {
//		std::cerr << ' ' << j;
		if (j <= n) {
			add(order[j], 1);
			if (order[n + q + j])
				add(order[n + q + j], -1);
		} else {
			ans[j - n] = query(order[j]);
		}
	}
//	std::cerr << '\n';
	for (const char c:sonchar[i]) {
		trie_clear2(trie[i].son[c]);
		trie[i].son[c] = 0;
	}
	sonchar[i].clear();
	sonchar[i].shrink_to_fit();
//	std::cerr << "leave " << i << '\n';
	for (int j = trie[i].id; j; j = nxt2[j]) {
		if (j <= n) {
			add(order[j], -1);
			if (order[n + q + j])
				add(order[n + q + j], 1);
		}
	}
	trie[i].id = 0;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	freopen("replace1.in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::cin >> q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> s[0][i];
		std::cin >> s[1][i];
	}
	for (int i = 1; i <= q; ++i) {
		std::cin >> t[0][i];
		std::cin >> t[1][i];
	}
	for (int i = 1; i <= n; ++i) {
		slen[i] = s[0][i].size();
		sl[i] = 0;
		while (sl[i] < slen[i] && s[0][i][sl[i]] == s[1][i][sl[i]])
			++sl[i];
		if (sl[i] == slen[i])
			continue;
		sr[i] = slen[i] - 1;
		while (s[0][i][sr[i]] == s[1][i][sr[i]])
			--sr[i];
		int u = trie_insert(1, s[0][i], sl[i], sr[i]);
//		for (int j = sl[i]; j <= sr[i]; ++j) {
//			if (!trie[u].son[s[0][i][j] - 'a']) {
//				++nodecnt;
//				trie[u].son[s[0][i][j] - 'a'] = nodecnt;
//			}
//			u = trie[u].son[s[0][i][j] - 'a'];
//		}
		if (!trie[u].id) {
			++nodecnt;
			trie[u].id = -nodecnt;
		}
		int v = trie_insert(-trie[u].id, s[1][i], sl[i], sr[i]);
//		for (int j = sl[i]; j <= sr[i]; ++j) {
//			if (!trie[v].son[s[1][i][j] - 'a']) {
//				++nodecnt;
//				trie[v].son[s[1][i][j] - 'a'] = nodecnt;
//			}
//			v = trie[v].son[s[1][i][j] - 'a'];
//		}
		nxt[i] = trie[v].id;
		trie[v].id = i;
	}
	for (int i = 1; i <= q; ++i) {
		tlen[i] = t[0][i].size();
		if (t[1][i].size() != tlen[i]) {
			ans[i] = 0;
			continue;
		}
		tl[i] = 0;
		while (t[0][i][tl[i]] == t[1][i][tl[i]])
			++tl[i];
		tr[i] = tlen[i] - 1;
		while (t[0][i][tr[i]] == t[1][i][tr[i]])
			--tr[i];
		int u = trie_query(1, t[0][i], tl[i], tr[i]);
//		for (int j = tl[i]; u && j <= tr[i]; ++j)
//			u = trie[u].son[t[0][i][j] - 'a'];
		int v = trie_query(-trie[u].id, t[1][i], tl[i], tr[i]);
//		for (int j = tl[i]; v && j <= tr[i]; ++j)
//			v = trie[v].son[t[1][i][j] - 'a'];
		if (v) {
			nxt[n + i] = trie[v].id;
			trie[v].id = n + i;
		} else {
			ans[i] = 0;
		}
	}
//	for (int i = 1; i <= n; ++i) {
//		if (!sr[i])
//			continue;
//		int u = 1;
//		for (int j = sl[i]; u && j <= sr[i]; ++j) {
//			int tmp = trie[u].son[s[0][i][j] - 'a'];
//			trie[u].son[s[0][i][j] - 'a'] = 0;
//			u = tmp;
//		}
//		int v = -trie[u].id;
//		for (int j = sl[i]; v && j <= sr[i]; ++j) {
//			int tmp = trie[v].son[s[1][i][j] - 'a'];
//			trie[v].son[s[1][i][j] - 'a'] = 0;
//			v = tmp;
//		}
//	}
//	for (int i = 1; i <= nodecnt; ++i) {
//		if (trie[i].id > 0) {
//			++headcnt;
//			head[headcnt] = trie[i].id;
//		}
//		trie[i].id = 0;
//	}

//	for (int i = 1; i <= nodecnt; ++i) {
//		std::cerr << i << ' ' << trie[i].id ;
//		for (const char c:sonchar[i])
//			std::cerr << ' ' << char(c + 'a') << ':' << trie[i].son[c];
//		std::cerr << '\n';
//	}
	trie_trie_clear(1);
	nodecnt = 1;
	for (int i = 1; i <= headcnt; ++i) {
		for (int j = head[i]; j; j = nxt[j]) {
//			std::cerr << ' ' << j;
			if (j <= n) {
				int u = trie_insert_reverse(1, s[0][j], sl[j] - 1);
				nxt2[j] = trie[u].id;
				trie[u].id = j;
				int k = 0;
				while (k < sl[j] && s[0][j][k] == 'z')
					++k;
				if (k < sl[j]) {
					++s[0][j][k];
					int u = trie_insert_reverse(1, s[0][j], sl[j] - 1);
					nxt2[n + q + j] = trie[u].id;
					trie[u].id = n + q + j;
				} else {
					order[n + q + j] = 0;
				}
			} else {
				int u = trie_insert_reverse(1, t[0][j - n], tl[j - n] - 1);
				nxt2[j] = trie[u].id;
				trie[u].id = j;
			}
		}
//		std::cerr << '\n';
		ordercnt = 0;
		trie_clear1(1);
		nodecnt = 1;
		for (int j = head[i]; j; j = nxt[j]) {
			if (j <= n) {
				int u = trie_insert(1, s[0][j], sr[j] + 1, slen[j] - 1);
				nxt2[j] = trie[u].id;
				trie[u].id = j;
			} else {
				int u = trie_insert(1, t[0][j - n], tr[j - n] + 1, tlen[j - n] - 1);
				nxt2[j] = trie[u].id;
				trie[u].id = j;
			}
		}
		trie_clear2(1);
		nodecnt = 1;
	}
	for (int i = 1; i <= q; ++i)
		std::cout << ans[i] << '\n';
	return 0;
}

