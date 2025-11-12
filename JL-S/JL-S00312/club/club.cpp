#include <bits/stdc++.h>
#define FILE_NAME "club"


using i32 = std::int32_t; using u32 = std::uint32_t;
using i64 = std::int64_t; using u64 = std::uint64_t;

/*
多测说是。
直接贪心，随便搞。
100
*/
namespace Solution {
namespace {
    char constexpr endl = '\n';
    auto solve() -> void {
        i32 n; std::cin >> n;
        std::vector<std::array<i32, 3>> a(n);
        for (auto &x : a) {
            for (auto &y : x) std::cin >> y;
        }

        std::vector<std::pair<i32, std::array<std::array<i32, 2>, 3>>> sorted;
        sorted.reserve(n);
        for (auto &x : a) {
            std::array<std::array<i32, 2>, 3> tmp{};
            for (i32 i = 0; i < 3; ++i) {
                tmp[i] = {x[i], i};
            }
            std::sort(tmp.begin(), tmp.end(), std::greater<>{});
            sorted.emplace_back(tmp[0][0] - tmp[1][0], tmp);
        }
        std::sort(sorted.begin(), sorted.end(), std::greater<>{});

        std::array<i32, 3> cnts{};
        i64 ans = 0;
        for (auto [_, favor] : sorted) {
            if (cnts[favor[0][1]] >= n / 2) {
                ++cnts[favor[1][1]];
                ans += favor[1][0];
            } else {
                ++cnts[favor[0][1]];
                ans += favor[0][0];
            }
        }
        std::cout << ans << endl;
    }
}
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen(FILE_NAME ".in", "r", stdin);
    std::freopen(FILE_NAME ".out", "w", stdout);

    i32 t; std::cin >> t;
    while (t --> 0)
        Solution::solve();

    return 0;
}