#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

uint64_t getHashChar(char c) {
	return c - 'a' + 1;
}

uint64_t appendChar(uint64_t hash, char c, const uint64_t MOD = 1000000007ull) {
	return (hash * 27 + getHashChar(c)) % MOD;
}

uint64_t gethash(std::string a, const uint64_t MOD = 1000000007ull) {
	uint64_t hash = 0;
	for (auto i : a) {
		hash = appendChar(hash, i, MOD);
	}
	return hash;
}

uint64_t qpow(uint64_t a, int b, const uint64_t MOD = 1000000007ull) {
	uint64_t ans = 1;

	while (b > 0) {
		if (b & 1) {
			ans = ans * a % MOD;
		}
		b >>= 1;
		a = a * a % MOD;
	}

	return ans;
}

uint64_t hashAppend(uint64_t a, uint64_t b, int lenb, const uint64_t MOD = 1000000007ull) {
	return (a * qpow(27, lenb) % MOD + b) % MOD;
}

int n, q;
std::pair<std::string, std::string> rules[200005];
std::pair<std::string, std::string> questions[200005];

std::unordered_map<std::string, std::unordered_map<std::string, int>> rulesMap;

// std::pair<uint64_t, uint64_t> hr[200005];
// std::pair<uint64_t, uint64_t> hq[200005];
// std::pair<uint64_t, uint64_t> prehr[200005];
// std::pair<uint64_t, uint64_t> prehq[200005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	bool specialB = true;
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> rules[i].first >> rules[i].second;
		
		++rulesMap[rules[i].first][rules[i].second];

		// hr[i].first = gethash(rules[i].first);
		// hr[i].second = gethash(rules[i].second);

		int Bt = 0;
		for (auto& c : rules[i].first) {
			Bt += (c == 'b');
		}
		if (Bt != 1) {
			specialB = false;
		}

		Bt = 0;
		for (auto& c : rules[i].second) {
			Bt += (c == 'b');
		}
		if (Bt != 1) {
			specialB = false;
		}
	}
	for (int i = 1; i <= q; ++i) {
		std::cin >> questions[i].first >> questions[i].second;
		// hq[i].first = gethash(questions[i].first);
		// hq[i].second = gethash(questions[i].second);


		int Bt = 0;
		for (auto& c : questions[i].first) {
			Bt += (c == 'b');
		}
		if (Bt != 1) {
			specialB = false;
		}


		Bt = 0;
		for (auto& c : questions[i].second) {
			Bt += (c == 'b');
		}
		if (Bt != 1) {
			specialB = false;
		}
	}

	for (int i = 1; i <= q; ++i) {
		int ans = 0;

		const auto& from = questions[i].first, to = questions[i].second;;
		std::string sf = from, st = to;
		reverse(sf.begin(), sf.end());
		reverse(st.begin(), st.end());

		while (!sf.empty()) {
			std::string rsf = sf, rst = st;
			reverse(rsf.begin(), rsf.end());
			reverse(rst.begin(), rst.end());

			while (!rsf.empty()) {
				ans += rulesMap[rsf][rst];

				if (rsf.back() != rst.back()) {
					break;
				}

				rsf.pop_back();
				rst.pop_back();
			}
			
			if (sf.back() != st.back()) {
				break;
			}

			sf.pop_back();
			st.pop_back();
		}

		std::cout << ans << "\n";
	}

	return 0;
}

// 10 pts
