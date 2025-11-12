#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int MAXN = 2e5 + 5;
const int MAXL = 5e6 + 5;
int n, q;
char s1[MAXL], s2[MAXL];
struct Hash {
	ull h1 = 0, h2 = 0; int len = 0;
	void operator+= (char c) { h1 = h1 * 97 + c, h2 = h2 * 113 + c, len++; }
	Hash operator+ (char c) {
		Hash ret = *this;
		ret += c;
		return ret;
	}
	bool operator== (Hash oth) {
		return this->h1 == oth.h1 && this->h2 == oth.h2 && this->len == oth.len;
	}
	void print() {
		printf("%llu %llu\n", h1, h2);
	}
} h[MAXN];
bool operator< (Hash x, Hash y) {
	if (x.len != y.len) return x.len < y.len;
	return x.h1 != y.h1 ? x.h1 < y.h1 : x.h2 < y.h2;
}
map<Hash, int> hid;
int hcnt;
int rt[MAXN], son[MAXL][26], pcnt;
vector<Hash> t[MAXL];
Hash H[MAXL];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int N = 1; N <= n; N++) {
		scanf("%s%s", s1 + 1, s2 + 1);
		int len = strlen(s1 + 1);
		int l = 1, r = len;
		while (s1[l] == s2[l] && l <= n) l++;
		while (s1[r] == s2[r] && r >= 1) r--;
//		printf("%d %d %d\n", len, l, r);
//		printf("%s %s\n", s1 + 1, s2 + 1);
		if (l > len) continue;
//		printf("!\n");
		for (int i = l; i <= r; i++) {
//			printf("i = %d\n", i);
			h[N] += s1[i];
			h[N] += s2[i];
//			printf("! %d %d\n", s1[i], s2[i]);
		}
//		h[N].print();
		if (hid[h[N]] == 0) hid[h[N]] = ++hcnt, rt[hcnt] = ++pcnt;
		int p = rt[hid[h[N]]];
		for (int i = r + 1; i <= len; i++) {
			if (!son[p][s1[i] - 'a']) son[p][s1[i] - 'a'] = ++pcnt;
			p = son[p][s1[i] - 'a'];
		}
		Hash H;
		for (int i = l - 1; i >= 1; i--) H += s1[i];
		t[p].push_back(H);
	}
//	printf("p_cnt = %d\n", pcnt);
//	printf("%d\n", son[1][0]);
	for (int Q = 1; Q <= q; Q++) {
		scanf("%s%s", s1 + 1, s2 + 1);
		int len = strlen(s1 + 1);
		int l = 1, r = len;
		while (s1[l] == s2[l]) l++;
		while (s1[r] == s2[r]) r--;
		Hash h;
		for (int i = l; i <= r; i++) h += s1[i], h += s2[i];
//		h.print();
		if (hid.find(h) == hid.end()) {
			printf("0\n");
			continue;
		}
		for (int i = l - 1, j = 1; i >= 1; i--, j++) {
			H[j] = H[j - 1] + s1[i];
		}
		int p = rt[hid[h]], ans = 0;
		for (Hash T : t[p])
			if (T == H[T.len])
				ans++;
		for (int i = r + 1; i <= len; i++) {
			if (!son[p][s1[i] - 'a']) break;
			p = son[p][s1[i] - 'a'];
//			printf("%d/%d %d\n", i, len, p);
			for (Hash T : t[p])
				if (T == H[T.len])
					ans++;
		}
//		if (Q == 103) {
//			printf("%s\n%s\n", s1 + 1, s2 + 1);
//			printf("%d\n", ans);
//		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

4 100
a b
aa ba
aa ab
aaa aba
aaaa abaa
aaaaa abaaa


*/
