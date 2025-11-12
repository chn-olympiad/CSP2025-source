#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int ALSIZ = 26;
constexpr i64 P = i64(1e18) + 9;
constexpr i64 B = 131;
inline i64 mul(i64 a, i64 b) {
	return i128(a) * b % P;
}
inline i64 norm(i64 x) {
	if (x < 0) {
		x += P;
	}
	if (x >= P) {
		x -= P;
	}
	return x;
}

template<typename T>
struct Fenwick {
	int n;
	std::vector<T> a;

	Fenwick(int n_ = 0) {
		init(n_);
	}

	void init(int n_) {
		n = n_;
		a.assign(n, T());
	}

	void add(int x, T const& d) {
		for (int i = x + 1; i <= n; i += i & -i) {
			a[i - 1] = a[i - 1] + d;
		}
	}

	T sum(int r) {
		T ans = T();
		for (int i = r; i > 0; i -= i & -i) {
			ans = ans + a[i - 1];
		}
		return ans;
	}
};

int32_t main() {
	std::freopen("replace.in", "r", stdin);
	std::freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, q;
	std::cin >> n >> q;

	std::vector<std::vector<std::string>> s(2, std::vector<std::string> (n));
	bool flag = true;
	for (int i = 0; i < n; i++) {
		std::cin >> s[0][i] >> s[1][i];

		if (flag) {
			int cnt = 0;
			for (auto ch : s[0][i]) {
				if (ch == 'b') {
					++cnt;
				} else if (ch != 'a') {
					flag = false;
				}
			}
			flag = flag && cnt == 1;
		}
		if (flag) {
			int cnt = 0;
			for (auto ch : s[1][i]) {
				if (ch == 'b') {
					++cnt;
				} else if (ch != 'a') {
					flag = false;
				}
			}
			flag = flag && cnt == 1;
		}
	}

	std::vector<std::vector<std::string>> t(2, std::vector<std::string> (q));
	std::vector<int> ans(q);
	for (int i = 0; i < q; i++) {
		std::cin >> t[0][i] >> t[1][i];

		if (flag) {
			int cnt = 0;
			for (auto ch : t[0][i]) {
				if (ch == 'b') {
					++cnt;
				} else if (ch != 'a') {
					flag = false;
				}
			}
			flag = flag && cnt == 1;
		}
		if (flag) {
			int cnt = 0;
			for (auto ch : t[1][i]) {
				if (ch == 'b') {
					++cnt;
				} else if (ch != 'a') {
					flag = false;
				}
			}
			flag = flag && cnt == 1;
		}
	}

	std::map<std::pair<i64, i64>, std::vector<std::tuple<int, std::string, std::string>>> type;
	for (int i = 0; i < n; i++) {
		int sl = 0, sr = int(s[0][i].size());
		for (; sl < sr && s[0][i][sl] == s[1][i][sl]; ++sl);
		for (; sl < sr && s[0][i][sr - 1] == s[1][i][sr - 1]; --sr);

		i64 M0 = 0, M1 = 0;
		for (int j = sl; j < sr; j++) {
			M0 = norm(mul(M0, B) + s[0][i][j]);
			M1 = norm(mul(M1, B) + s[1][i][j]);
		}
		std::string L = "", R = "";
		for (int j = sl - 1; j >= 0; j--) {
			L.push_back(s[0][i][j]);
		}
		for (int j = sr; j < int(s[0][i].size()); j++) {
			R.push_back(s[0][i][j]);
		}
		type[{M0, M1}].emplace_back(-1, L, R);
	}

	for (int i = 0; i < q; i++) {
		if (t[0][i].size() != t[1][i].size()) {
			continue;
		}
		int tl = 0, tr = int(t[0][i].size());
		for (; tl < tr && t[0][i][tl] == t[1][i][tl]; ++tl);
		for (; tl < tr && t[0][i][tr - 1] == t[1][i][tr - 1]; --tr);

		i64 M0 = 0, M1 = 0;
		for (int j = tl; j < tr; j++) {
			M0 = norm(mul(M0, B) + t[0][i][j]);
			M1 = norm(mul(M1, B) + t[1][i][j]);
		}
		std::string L = "", R = "";
		for (int j = tl - 1; j >= 0; j--) {
			L.push_back(t[0][i][j]);
		}
		for (int j = tr; j < int(t[0][i].size()); j++) {
			R.push_back(t[0][i][j]);
		}
		type[{M0, M1}].emplace_back(i, L, R);
	}

//	// test
//	for (auto const& zip : type) {
//		auto const& vec = std::get<1>(zip);
//		for (auto zip : vec) {
//			std::cout << std::get<0>(zip) << " " << std::get<1>(zip) << " " << std::get<2>(zip) << "\n";
//		}
//		std::cout << "--------\n";
//	}

	auto solve = [&](std::vector<std::tuple<int, std::string, std::string>> const& str) -> void {
		std::vector<std::pair<i64, i64>> a;
		for (auto zip : str) {
			auto qid = std::get<0>(zip);
			if (qid == -1) {
				i64 x = 0;
				for (auto ch : std::get<1>(zip)) {
					x = norm(mul(x, B) + ch);
				}
				i64 y = 0;
				for (auto ch : std::get<2>(zip)) {
					y = norm(mul(y, B) + ch);
				}
				a.emplace_back(x, y);
			}
		}
		for (auto zip : str) {
			auto qid = std::get<0>(zip);
			if (qid != -1) {
				std::vector<i64> x(int(std::get<1>(zip).size()) + 1);
				for (int i = 0; i < int(std::get<1>(zip).size()); i++) {
					x[i + 1] = norm(mul(x[i], B) + std::get<1>(zip)[i]);
				}
				std::vector<i64> y(int(std::get<2>(zip).size()) + 1);
				for (int i = 0; i < int(std::get<2>(zip).size()); i++) {
					y[i + 1] = norm(mul(y[i], B) + std::get<2>(zip)[i]);
				}
				std::set<i64> X(x.begin(), x.end()), Y(y.begin(), y.end());
				for (auto zip : a) {
					auto u = std::get<0>(zip);
					auto v = std::get<1>(zip);
					if (X.count(u) && Y.count(v)) {
						++ans[qid];
					} 
				}
			}
		}
	};

	for (auto& zip : type) {
		solve(std::get<1>(zip));
	}

	for (int i = 0; i < q; i++) {
		std::cout << ans[i] << "\n";
	}

	return 0;
}

