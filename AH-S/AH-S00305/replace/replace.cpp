#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <type_traits>
#include <map>
#include <unordered_set>
#ifdef DEBUG
# define debug(...) fprintf(stderr, __VA_ARGS__)
#else
# define debug(...) ((void)0)
#endif
using std::min; using std::max; using std::abs;
#define For(i, s, t) for (int i = (s); i <= (t); ++i)
#define roF(i, t, s) for (int i = (t); i >= (s); --i)
namespace FastI {
	char buf[1 << 20], *p1=nullptr, *p2=nullptr;
	inline char gc() { if (p1 == p2) p2 = (p1=buf) + fread(buf, 1, sizeof buf, stdin); return *p1++; }
	inline void in(char &x) { do x = gc(); while (x == ' ' || x == '\n' || x == '\r'); }
	inline void in(int &x) {
		char ch = gc();
		while (ch < '0' || ch > '9') ch = gc();
		for (x = ch ^ '0', ch = gc(); ch >= '0' && ch <= '9'; ch = gc())
			x = (x << 3) + (x << 1) + (ch ^ '0');
	}
	inline void in(char *s) {
		do *s = gc(); while (*s == ' ' || *s == '\n' || *s == '\r');
		do *(++s) = gc(); while (*s != ' ' && *s != '\n' && *s != '\r');
		*s = '\0';
	}
} using FastI::in;

using Hash_t = std::pair<unsigned long long, unsigned long long>;
constexpr int N = 200005, L = 5000005;
constexpr unsigned long long B = 31, P = 1000'0000'0000'0000'7ULL;
struct TrieNode {
	std::unordered_set<int> ht;
	std::map<char, int> son;
} tr[L * 3];
int tot=0;
void ins_fw(int u, char *st, char *p, const int hash) { // ed->st
	while (p >= st) {
		int &v = tr[u].son[*p];
		if (!v) v = ++tot;
		u = v;
		--p;
	}
	tr[u].ht.emplace(hash);
}
void ins_bk(int u, char *p, char *ed, const int hash) {
	while (p <= ed) {
		int &v = tr[u].son[*p];
		if (!v) v = ++tot;
		u = v;
		++p;
	}
	tr[u].ht.emplace(hash);
}
std::unordered_set<int> chk_fw(int u, char *st, char *p) {
	std::unordered_set<int> res;
	while (p >= st) {
		for (int i : tr[u].ht) res.insert(i);
		u = tr[u].son[*p];
		--p;
	}
	for (int i : tr[u].ht) res.insert(i);
	return res;
}
std::unordered_set<int> chk_bk(int u, char *p, char *ed) {
	std::unordered_set<int> res;
	while (p <= ed) {
		for (int i : tr[u].ht) res.insert(i);
		u = tr[u].son[*p];
		++p;
	}
	for (int i : tr[u].ht) res.insert(i);
	return res;
}
Hash_t calc_hash(char *st, char *ed) {
	Hash_t hash;
	while (st <= ed) {
		hash.first = hash.first * B + (*st - 'a');
		hash.second = (hash.second * B + (*st - 'a')) % P;
		st++;
	}
	return hash;
}
char s[2][L], news[L << 1];
std::map<Hash_t, std::pair<int,int>> mp;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	in(n), in(q);
	For (i, 1, n) {
		in(s[0]), in(s[1]);
		int front = 0, back = strlen(s[0])-1;
		if (strcmp(s[0], s[1])) {
			while (s[0][front] == s[1][front]) ++front;
			while (s[0][back] == s[1][back]) --back;
		}
		debug("%d %d\n", front, back);
		int len = back - front + 1;
		For (i, front, back) news[i - front] = s[0][i];
		For (i, front, back) news[i - front + len] = s[1][i];
		Hash_t hash = calc_hash(news, news + 2*len - 1);
		auto &pir = mp[hash];
		if (!pir.first) pir.first = ++tot;
		if (!pir.second) pir.second = ++tot;
		ins_fw(pir.first, s[0], s[0] + front - 1, i);
		ins_bk(pir.second, s[0] + back + 1, s[0] + strlen(s[0]) - 1, i);
	}
	For (_q, 1, q) {
		in(s[0]), in(s[1]);
		int front = 0, back = strlen(s[0])-1;
		if (strcmp(s[0], s[1])) {
			while (s[0][front] == s[1][front]) ++front;
			while (s[0][back] == s[1][back]) --back;
		}
		// debug("%d %d\n", front, back);
		int len = back - front + 1;
		For (i, front, back) news[i - front] = s[0][i];
		For (i, front, back) news[i - front + len] = s[1][i];
		Hash_t hash = calc_hash(news, news + 2*len - 1);
		auto pir = mp[hash];
		int ans = 0;
		if (pir.first && pir.second) {
			auto mp1 = chk_fw(pir.first, s[0], s[0] + front - 1);
			auto mp2 = chk_bk(pir.second, s[0] + back + 1, s[0] + strlen(s[0]) - 1);
			for (int i : mp1) {
				// debug("%d\n", i);
				if (mp2.count(i)) ++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
