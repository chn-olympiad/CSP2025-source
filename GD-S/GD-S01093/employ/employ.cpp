#include <bits/stdc++.h>

namespace employ {
    using i64 = std::int64_t;
    using u64 = std::uint64_t;
    
    constexpr auto operator""_uz(unsigned long long num) {
        return static_cast<std::size_t>(num);
    }
    
    std::ifstream fin("employ.in");
    std::ofstream fout("employ.out");

    constexpr auto mod = 998244353ull;

    bool avail[505];
    u64 limit[505];
    u64 f[505];
    bool picked[505]{ };

    std::size_t n, m;

    u64 search(std::size_t i, std::size_t fails) {
        if ((i - fails) >= m) return f[i];
        if (i >= n || (n - i) < (m - (i - fails))) return 0ull;
        const auto &a = avail[i];
        auto r = 0ull;
        for (auto j = 0_uz; j < n; ++j) {
            if (picked[j]) continue;
            picked[j] = true;

            if (!a || limit[j] <= fails) {
                r += search(i + 1, fails + 1);
            } else {
                r += search(i + 1, fails);
            }
            picked[j] = false;
        }
        return r;
    }

    inline void main() {
        fin >> n >> m;

        std::string str;
        fin >> str;

        for (auto i = 0_uz; i < n; ++i) {
            fin >> limit[i];
            avail[i] = str[i] != '0';
        }

        std::sort(limit + 0, limit + n, std::greater<u64>());

        f[1] = 1ull;
        for (auto i = 2_uz; i <= n; ++i) f[i] = (f[i - 1] * static_cast<u64>(i)) % mod;

        fout << search(0, 0);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    employ::main();

    std::cout.flush();
    employ::fout.flush();
    employ::fout.close();
}