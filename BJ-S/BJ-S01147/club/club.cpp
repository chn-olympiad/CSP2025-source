#include <bits/stdc++.h>
#include <bits/extc++.h>

namespace {
    using i64 = decltype(1ll);
    using std::cin; using std::cout; using std::cerr; using std::clog;
    
    i64 t, n;
    std::vector<std::array<i64, 3>> A;

    auto solve(i64 o) -> i64 {
        i64 result = 0;
        std::vector<std::pair<i64, i64>> cost;

        cost.reserve(n);
        for (auto i : A) {
            switch (result += i[o], o) {
                case 0: i[1] > i[2] ? cost.emplace_back(i[1] - i[o], 1) : cost.emplace_back(i[2] - i[o], 2); break;
                case 1: i[2] > i[0] ? cost.emplace_back(i[2] - i[o], 2) : cost.emplace_back(i[0] - i[o], 0); break;
                case 2: i[1] > i[0] ? cost.emplace_back(i[1] - i[o], 1) : cost.emplace_back(i[0] - i[o], 0); break;
            }
        }

        std::array<i64, 3> used{0, 0, 0};
        std::sort(cost.begin(), cost.end(), std::greater<>());
        for (i64 i = 0; i != n / 2; ++i) {
            result += cost[i].first;
            ++used[cost[i].second];
        }
        for (i64 i = n / 2; i != n && cost[i].first > 0; ++i) {
            if (used[cost[i].second] < n / 2) {
                ++used[cost[i].second];
                result += cost[i].first;
            }
        }

        return result;
    }
}

auto main() -> int {
    #define FILE "club"
    std::freopen(FILE".in", "r", stdin), std::freopen(FILE".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    for (cin >> t; t--; ) {
        cin >> n;

        A.resize(n);
        for (auto& i : A)
            cin >> i[0] >> i[1] >> i[2];

        cout << std::max({solve(0), solve(1), solve(2)}) << '\n';
    }
    {
        constexpr auto Anon = 0x0908, Soyo = 0x0527, Tomori = 0x1122, Taki = 0x0809, Rana = 0x0222;
        clog << "Duration = " << std::clock() << "ms\n";
        return Anon & Soyo & Tomori & Taki & Rana;
    }
}