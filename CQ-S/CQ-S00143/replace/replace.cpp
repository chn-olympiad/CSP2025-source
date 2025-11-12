#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using i32 = int;
using u64 = unsigned long long;
constexpr i32 N = 2E5, L = 5E6, B = 200;
constexpr u64 Base = 233;
u64 pw[L + 1], h1[L + 1], h2[L + 1];
auto hash = [](u64 *h, i32 l, i32 r) noexcept { return l > r ? 0 : h[r] - (l ? h[l - 1] : 0) * pw[r - l + 1]; };
i32 n, q;
std::string s1[N + 1], s2[N + 1];
u64 hl1[N + 1], hr1[N + 1], hl2[N + 1], hr2[N + 1];
std::string t1, t2;
i32 ls[N + 1], rs[N + 1];
std::vector<i32> rider;
std::map<std::pair<u64, u64>, i32> caster;
std::map<std::pair<u64, u64>, std::vector<i32>> assasin;
signed main() noexcept {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	pw[0] = 1;
	for (i32 i = 1; i <= L; ++i) pw[i] = pw[i - 1] * Base;
	std::cin >> n >> q;
	for (i32 i = 1; i <= n; ++i) {
		std::cin >> s1[i] >> s2[i];
		for (i32 j = 0; j < i32(s2[i].size()); ++j) h1[j] = (j ? h1[j - 1] : 0) * Base + s1[i][j], h2[j] = (j ? h2[j - 1] : 0) * Base + s2[i][j];
		if (s1[i].size() <= B) {
			rider.emplace_back(s1[i].size());
			++caster[{hash(h1, 0, s1[i].size() - 1), hash(h2, 0, s2[i].size() - 1)}];
			continue;
		}
		ls[i] = 0, rs[i] = s1[i].size() - 1;
		while (ls[i] <= rs[i] && s1[i][ls[i]] == s2[i][ls[i]]) ++ls[i];
		while (ls[i] <= rs[i] && s1[i][rs[i]] == s2[i][rs[i]]) --rs[i];
		assasin[{hash(h1, ls[i], rs[i]), hash(h2, ls[i], rs[i])}].emplace_back(i);
		hl1[i] = hash(h1, 0, ls[i] - 1), hr1[i] = hash(h1, rs[i] + 1, s1[i].size() - 1);
		hl2[i] = hash(h2, 0, ls[i] - 1), hr2[i] = hash(h2, rs[i] + 1, s2[i].size() - 1);
	}
	std::sort(rider.begin(), rider.end());
	rider.erase(std::unique(rider.begin(), rider.end()), rider.end());
	for (; q; --q) {
		std::cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			puts("0");
			continue;
		}
		i32 lt = 0, rt = t1.size();
		while (lt <= rt && t1[lt] == t2[lt]) ++lt;
		while (lt <= rt && t1[rt] == t2[rt]) --rt;
		i32 ans = 0;
		for (i32 i = 0; i < i32(t2.size()); ++i) h1[i] = (i ? h1[i - 1] : 0) * Base + t1[i], h2[i] = (i ? h2[i - 1] : 0) * Base + t2[i];
		for (i32 i : assasin[{hash(h1, lt, rt), hash(h2, lt, rt)}]) {
			if (lt < ls[i] || t2.size() - rt < s1[i].size() - rs[i]) continue;
			if (hash(h1, lt - ls[i], lt - 1) == hl1[i] && hash(h1, rt + 1, rt + s1[i].size() - rs[i] - 1) == hr1[i] && hash(h2, lt - ls[i], lt - 1) == hl2[i] && hash(h2, rt + 1, rt + s1[i].size() - rs[i] - 1) == hr2[i])
				++ans;
		}
		for (i32 j : rider)
			for (i32 i = std::max(0, rt + 1 - j); i <= std::min(lt, i32(t1.size()) - j); ++i) {
				auto itr = caster.find({hash(h1, i, i + j - 1), hash(h2, i, i + j - 1)});
				if (itr != caster.end()) ans += itr->second;
			}
		printf("%d\n", ans);
	}
	return 0;
}
/*
闭嘴，我在传说zaou分级玩马噶列阵兵，如果你惹恼了我，我就会背水一战，然后吃下六次抛下狠话直到双攻-6
*/