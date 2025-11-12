#include <bits/stdc++.h>
#define ft first
#define sd second
#define int long long

template<typename T> void read(T &x) {
	x = 0; char s = getchar();
	for (; !isdigit(s); ) s = getchar();
	for (; isdigit(s); s = getchar()) x = (x << 3) + (x << 1) + s - '0';
}

template<typename T> void ckmax(T &x, T y) { x = x > y ? x : y; }
template<typename T> void ckmin(T &x, T y) { x = x < y ? x : y; }
template<typename T> void ckadd(T &x, T y, T p) { x = (x + y) % p; }
template<typename T> void ckmul(T &x, T y, T p) { x = (x * y) % p; }

const int N = 2e5 + 7;
const int M = 5e5 + 7;

std::string s1[N], s2[N], t1, t2;
std::pair<int, int> h1[N], h2[N];
std::map<std::pair<int, int>, std::pair<int, int> > mp;

int n, Q, ans;

namespace HASH1 {
	const int Mod = 1e9 + 7;
	const int mod = 998244353;
	const int P = 131;
	std::pair<int, int> h[M];
	int p1[M], p2[M];
	std::pair<int, int> getH(std::string S, int l, int r) {
		std::pair<int, int> res = { 0, 0 };
		for (int i = l; i <= r; i ++)
			res.ft = (res.ft * P + S[i]) % Mod,
			res.sd = (res.sd * P + S[i]) % mod;
		
		return res;
	}
	std::pair<int, int> H(int l, int r) {
		if (!l) return h[r];
		else return { (h[r].ft - h[l - 1].ft * p1[r - l + 1] % Mod + Mod) % Mod, 	(h[r].sd - h[l - 1].sd * p2[r - l + 1] % mod + mod) % mod };
	}
	void PreWork(std::string S) {
		h[0] = { S[0], S[0] }; p1[0] = p2[0] = 1;
		for (int i = 1; i <= S.size(); i ++) p1[i] = p1[i - 1] * P % Mod, p2[i] = p2[i - 1] * P % mod;
		for (int i = 1; i < S.size(); i ++)
			h[i].ft = (h[i - 1].ft * P + S[i]) % Mod,
			h[i].sd = (h[i - 1].sd * P + S[i]) % mod;
	}
}

namespace HASH2 {
	const int Mod = 1e9 + 7;
	const int mod = 998244353;
	const int P = 131;
	std::pair<int, int> h[M];
	int p1[M], p2[M];
	std::pair<int, int> H(int l, int r) {
		if (!l) return h[r];
		else return { (h[r].ft - h[l - 1].ft * p1[r - l + 1] % Mod + Mod) % Mod, 
									(h[r].sd - h[l - 1].sd * p2[r - l + 1] % mod + mod) % mod };
	}
	void PreWork(std::string S) {
		h[0] = { S[0], S[0] }; p1[0] = p2[0] = 1;
		for (int i = 1; i <= S.size(); i ++) p1[i] = p1[i - 1] * P % Mod, p2[i] = p2[i - 1] * P % mod;
		for (int i = 1; i < S.size(); i ++)
			h[i].ft = (h[i - 1].ft * P + S[i]) % Mod,
			h[i].sd = (h[i - 1].sd * P + S[i]) % mod;
	}
}

signed main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	read(n), read(Q); for (int i = 1; i <= n; i ++) std::cin >> s1[i] >> s2[i];
	for (int i = 1; i <= n; i ++) mp[HASH1::getH(s1[i], 0, s1[i].size() - 1)] = HASH1::getH(s2[i], 0, s2[i].size() - 1);
	while (Q --) {
		std::cin >> t1 >> t2; int ans = 0;
		int l = 0; for (; l < t1.size() && t1[l] == t2[l]; l ++);
		int r = t1.size() - 1; for (; ~r && t1[r] == t2[r]; r --);
		HASH1::PreWork(t1); HASH2::PreWork(t2);
		for (int i = 0; i <= l; i ++) for (int j = r; j < t1.size(); j ++)
			if (mp.find(HASH1::H(i, j)) != mp.end() && mp[HASH1::H(i, j)] == HASH2::H(i, j))
				ans ++;
		printf("%lld\n", ans);
	}
	
	return 0;
}
