//GZ-S00393 蒋晨阳 遵义市第四中学
#include <bits/stdc++.h>
using d32 = int;
using u32 = unsigned;
using d64 = long long;
using u64 = unsigned long long;
#define a2pow32(x)	(31 - __builtin_clz(x))
u64 kpow[5000000];
template <class Tp>
u64 _rhash(Tp bg, Tp ed) {
	u64 ans = 0;
	while (bg != ed)	ans = ans * 1331 + *bg++;
	return ans;
}
struct rhash {
	std::vector<u64> arr;
	template <class Tp>
	rhash(Tp bg, Tp ed) {
		u32 n = ed - bg;
		arr.reserve(n + 1), arr.push_back(0);
		for (u32 i = 0; i < n; ++i)	arr.push_back(arr.back() * 1331 + *bg++);
	}
	u64 operator()(u32 bg, u32 ed) {
		return arr[ed] - arr[bg] * kpow[ed - bg];
	}
};
int main() {
#ifndef _0x3C17_
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::cin.tie(0)->sync_with_stdio(0);
#endif
	kpow[0] = 1;
	for (u32 i = 1; i < 5000000; ++i)	kpow[i] = kpow[i - 1] * 1331;
	u32 n, q;
	std::cin >> n >> q;
	std::string s[200000][2];
	u64 hs[200000][2];
	//return 0;
	for (u32 i = 0; i < n; ++i)
		std::cin >> s[i][0] >> s[i][1],
		hs[i][0] = _rhash(s[i][0].begin(), s[i][0].end()),
		hs[i][1] = _rhash(s[i][1].begin(), s[i][1].end());
	for (u32 i = 0; i < q; ++i) {
		std::string t0, t1;
		std::cin >> t0 >> t1;
		rhash h0(t0.begin(), t0.end()), h1(t1.begin(), t1.end());
		u32 ans = 0;
		for (u32 j = 0; j < n; ++j) {
			for (u32 i = 0; i + s[i][0].size() <= t0.size(); ++i) {
				if (h0(i, i + s[i][0].size()) == hs[j][0] &&
					h1(i, i + s[i][1].size()) == hs[j][1] && 
					h0(0, i) == h1(0, i) &&
					h0(i + s[i][0].size(), t0.size()) ==
						h1(i + s[i][1].size(), t1.size()))
					++ans;
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}
