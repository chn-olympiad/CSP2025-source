#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define PROBLEM_NAME "replace"
#define MULTIPLE_TEST 0

struct Solver {
	struct In {
		int n, q;
		std::string s[200010][2];
		std::string t[200010][2];
		In() {
			std::cin >> n >> q;
			for (int i = 1; i <= n; i++)
				std::cin >> s[i][0] >> s[i][1];
			for (int i = 1; i <= q; i++)
				std::cin >> t[i][0] >> t[i][1];
		}
	} in;
	struct Out {
		int q;
		int ans[200010];
		~Out() {
			for (int i = 1; i <= q; i++)
				std::cout << ans[i] << '\n';
		}
	} out;
	Solver() { out.q = in.q; }
	inline void slice(std::string *src, std::string &dst1, 
	                  std::string &dst2, std::string &dst3) {
		int l = 0, r = src[0].size() - 1;
		while (l <= r && src[0][l] == src[1][l]) l++;
		while (l <= r && src[0][r] == src[1][r]) r--;
		dst1.clear(), dst2.clear(), dst3.clear();
		for (int i = l - 1; ~i; i--) dst1 += src[0][i];
		for (int i = l; i <= r; i++)
			dst2 += src[0][i], dst2 += src[1][i];
		for (int i = r + 1; i < src[0].size(); i++)
			dst3 += src[0][i];
	}
	// Solution 1.
	std::unordered_map<std::string, std::unordered_map<int, std::vector<int>>> m1;
	std::unordered_map<std::string, std::unordered_map<int, std::vector<int>>> m2;
	bool bkt[200010];
	inline int extend(int hsh, char ch) {
		return (131LL * hsh + ch) % 1000000009;
	}
	inline int hashh(std::string s) {
		int hsh = 0;
		for (char ch : s)
			hsh = extend(hsh, ch);
		return hsh;
	}
	inline void Work() {
		std::string d1, d2, d3;
		for (int i = 1; i <= in.n; i++) {
			slice(in.s[i], d1, d2, d3);
			m1[d2][hashh(d1)].emplace_back(i);
			m2[d2][hashh(d3)].emplace_back(i);
		}
		int hsh;
		for (int i = 1; i <= in.q; i++) {
			slice(in.t[i], d1, d2, d3);
			auto &p = m1[d2];
			auto &q = m2[d2];
			for (int j = hsh = 0; j <= d1.size(); j++) {
				for (int id : p[hsh]) bkt[id] = true;
				if (j < d1.size())
					hsh = extend(hsh, d1[j]);
			}
			for (int j = hsh = 0; j <= d3.size(); j++) {
				for (int id : q[hsh]) out.ans[i] += bkt[id];
				if (j < d3.size())
					hsh = extend(hsh, d3[j]);
			}
			for (int j = hsh = 0; j <= d1.size(); j++) {
				for (int id : p[hsh]) bkt[id] = false;
				if (j < d1.size())
					hsh = extend(hsh, d1[j]);
			}
		}
	}
};

int main() {
	static uint8_t space[sizeof(Solver)];
	freopen(PROBLEM_NAME ".in", "r", stdin);
	freopen(PROBLEM_NAME ".out", "w", stdout);
	// Overriding stdin/stdout, evil but working...
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	int T;
#if MULTIPLE_TEST == 1
	std::cin >> T;
#else
	T = 1;
#endif
	while (T--) {
		Solver *solver = new (space) Solver();
	       	solver -> Work();
		solver -> ~Solver();
		if (T) memset(space, 0, sizeof(space));
	}
	return 0;
}
#undef PROBLEM_NAME
#undef MULTIPLE_TEST