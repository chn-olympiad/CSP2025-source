#include <bits/stdc++.h>

#define int long long

const int N = 2e5 + 5, M = 5e6 + 5;

int n, m;
std::string s1[N], s2[N], t1[N], t2[N];
int lens[N], lent[N];

namespace SubBF {

const int base = 233, mod = 998244353;

int b[M];
int h1[N], h2[N], a1[M], a2[M];
inline int get1(int l, int r) {
	return (a1[r] - a1[l - 1] * b[r - l + 1] % mod + mod) % mod;
}

inline int get2(int l, int r) {
	return (a2[r] - a2[l - 1] * b[r - l + 1] % mod + mod) % mod;
}

void solve(std::string& t1, std::string& t2, int len) {
	for (int i = 1; i <= len; ++i)
		a1[i] = (a1[i - 1] * base + t1[i]) % mod,
		a2[i] = (a2[i - 1] * base + t2[i]) % mod;
	int l = 1, r = len;
	while (t1[l] == t2[l]) ++l;
	while (t1[r] == t2[r]) --r;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int st = 1; st <= len; ++st)
			if (st <= l && st + lens[i] - 1 <= len && st + lens[i] - 1 >= r)
				if (h1[i] == get1(st, st + lens[i] - 1) && h2[i] == get2(st, st + lens[i] - 1))
					++ans;
	std::cout << ans << std::endl;
}

void Main() {
	b[0] = 1;
	for (int i = 1; i <= 5e6; ++i)
		b[i] = b[i - 1] * base % mod;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= lens[i]; ++j)
			h1[i] = (h1[i] * base + s1[i][j]) % mod,
			h2[i] = (h2[i] * base + s2[i][j]) % mod;
	for (int i = 1; i <= m; ++i)
		solve(t1[i], t2[i], lent[i]);
}

}

namespace SubA {

int l[N], r[N], k_[N];
void solve(std::string& t1, std::string& t2, int len) {
	int L, R, k;
	int p1 = 0, p2 = 0;
	for (int i = 1; i <= len; ++i)
		if (t1[i] == 'b') {
			p1 = i;
			break;
		}
	for (int i = 1; i <= len; ++i)
		if (t2[i] == 'b') {
			p2 = i;
			break;
		}
	k = p2 - p1;
	L = std::min(p1, p2) - 1;
	R = len - std::max(p1, p2);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (l[i] <= L && r[i] <= R && k_[i] == k)
			++ans;
	std::cout << ans << std::endl;
}

void Main() {
	for (int i = 1, p1, p2; i <= n; ++i) {
		p1 = p2 = 0;
		for (int j = 1; j <= lens[i]; ++j)
			if (s1[i][j] == 'b') {
				p1 = j;
				break;
			}
		for (int j = 1; j <= lens[i]; ++j)
			if (s2[i][j] == 'b') {
				p2 = j;
				break;
			}
		k_[i] = p2 - p1;
		l[i] = std::min(p1, p2) - 1;
		r[i] = lens[i] - std::max(p1, p2);
	}
	for (int i = 1; i <= m; ++i)
		solve(t1[i], t2[i], lent[i]);
}

}

inline bool check(std::string& s, int n) {
	bool vis = false;
	for (int i = 1; i <= n; ++i) {
		if (s[i] != 'a' && s[i] != 'b') return false;
		if (s[i] == 'b') {
			if (vis) return false;
			vis = true;
		}
	}
	return true;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> s1[i] >> s2[i];
		lens[i] = s1[i].size();
		s1[i] = " " + s1[i];
		s2[i] = " " + s2[i];
	}
	for (int i = 1; i <= m; ++i) {
		std::cin >> t1[i] >> t2[i];
		lent[i] = t1[i].size();
		t1[i] = " " + t1[i];
		t2[i] = " " + t2[i];
	}
	bool keyA = true;
	for (int i = 1; i <= n; ++i)
		if (!check(s1[i], lens[i]) || !check(s2[i], lens[i])) {
			keyA = false;
			break;
		}
	for (int i = 1; i <= n; ++i)
		if (!keyA || !check(t1[i], lent[i]) || !check(t2[i], lent[i])) {
			keyA = false;
			break;
		}
	SubBF::Main();
//	if (keyA) SubA::Main();
//	else SubBF::Main();
	return 0;
}
