#include <bits/stdc++.h>
#define FILE_NAME "employ"


using i32 = std::int32_t; using u32 = std::uint32_t;
using i64 = std::int64_t; using u64 = std::uint64_t;

/*
8
*/
namespace Solution {
namespace {
    char constexpr endl = '\n';
    auto solve() -> void {
        i32 n, m;
        std::cin >> n >> m;

        std::vector<char> s(n);
        std::vector<i32> c(n);
        for (auto &x : s) std::cin >> x;
        for (auto &x : c) std::cin >> x;

        std::vector<i32> order(n);
        for (i32 i = 0; i < n; ++i) order[i] = i;

        i32 tot = 0;
        do {
            i32 denied = 0;
            i32 cnt = 0;
            for (i32 i = 0; i < n; ++i) {
                auto p = order[i];
                if (denied >= c[p] || s[i] == '0') ++denied;
                else ++cnt;
            }
            if (cnt >= m) {
                ++tot;
            }
        } while (std::next_permutation(order.begin(), order.end()));

        std::cout << tot << endl;
    }
}
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen(FILE_NAME ".in", "r", stdin);
    std::freopen(FILE_NAME ".out", "w", stdout);

    Solution::solve();

    return 0;
}