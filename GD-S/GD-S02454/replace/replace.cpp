#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstring>

using namespace std;

namespace Main {

typedef long long LL;
typedef __int128_t LI;

LL read() {
	LL ch, res = 0, f = 0;
	for (ch = getchar(); (ch < '0' || ch > '9') && ch != '-'; ch = getchar());
	if (ch == '-') {
		f = 1;
		ch = getchar();
	}
	for (; '0' <= ch && ch <= '9'; ch = getchar())
		res = res * 10 + (ch & 15);
	return f ? -res : res;
}

constexpr int T = 0;
constexpr int N = 5000005, M = 26, B = 31;
constexpr LL MOD = 1e17 + 13;

char a[N], b[N];
int tr[N][M], s[N], ans[N], tot;

unordered_map<LL, int> mp;
vector<int> vc[N];
string s0[N], s1[N];
pair<int, int> sk[N];

int lcp(string &x, string &y) {
	for (int i = 0; i < x.size() && i < y.size(); ++i)
		if (x[i] != y[i])
			return i;
	return min(x.size(), y.size());
}

int add(string &st) {
	int p = 1;
	for (int i : st) {
		if (!tr[p][i - 'a'])
			tr[p][i - 'a'] = ++tot;
		p = tr[p][i - 'a'];
	}
//	printf("add #%d\n", p);
	++s[p];
	return p;
}

int query(string &st) {
	int p = 1, res = s[1];
	for (int i : st) {
		if (!tr[p][i - 'a'])
			break;
		p = tr[p][i - 'a'];
		res += s[p];
//		printf("q %d\n", p);
	}
	return res;
}

void solve(int n, vector<int> &vc) {
//	puts("fjldks");
	sort(vc.begin(), vc.end(), [](int x, int y){return s0[x] < s0[y] || (x < y && s0[x] == s0[y]);});
	string st;
	int tot = 0;
	for (int k : vc) {
		for (int lc = lcp(st, s0[k]); tot && sk[tot].first > lc; --tot) {
			--s[sk[tot].second];
//			printf("del %d\n", sk[tot].second);
		}
		st = s0[k];
//		printf("#%d\n", k);
		if (k <= n) {
			sk[++tot] = make_pair(s0[k].size(), add(s1[k]));
//			printf("add %d\n", s0[k].size());
		} else 
			ans[k - n] = query(s1[k]);
	}
	for (; tot; --tot)
		s[sk[tot].second] = 0;
	return;
}


void solve() {
//	printf("%d\n", sizeof(tr) / 1024 / 1024);
	int n = read(), q = read(), to = 0;
	tot = 1;
	for (int i = 1; i <= n + q; ++i) {
		scanf("%s %s", a, b);
		int len = strlen(a), l = 0, r = len;
		for (; l < len && a[l] == b[l]; ++l);
		if (l == len)
			continue;
		for (; ~r && a[r] == b[r]; --r);
		LI hs = 0;
		for (int j = l; j <= r; ++j)
			hs = (hs * B + a[j] - 'a' + 1) % MOD;
		for (int j = l; j <= r; ++j)
			hs = (hs * B + b[j] - 'a' + 1) % MOD;
		reverse(a, a + l);
		a[l] = b[l] = 0;
		s0[i] = a;
		s1[i] = a + r + 1;
		if (!mp.count(hs))
			mp[hs] = ++to;
		vc[mp[hs]].emplace_back(i);
	}
	for (int i = 1; i <= to; ++i) {
		solve(n, vc[i]);
	}
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);

	return;
}

void main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	for (int t = T ? read() : 1; t; --t)
		solve();
	fclose(stdin);
	fclose(stdout);
	return;
}
}

int main() {
	Main::main();
	return 0;
}
