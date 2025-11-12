#include <bits/stdc++.h>
#include <bits/extc++.h>

namespace {
    using i64 = decltype(1ll);
    using std::cin; using std::cout; using std::cerr; using std::clog;

    constexpr i64 M = 998244353;

    i64 n, m;
    std::string s;
    std::vector<i64> A, P;
}

auto main() -> int {
    #define FILE "employ"
    std::freopen(FILE".in", "r", stdin), std::freopen(FILE".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> s;

    A.resize(n);
    for (auto& i : A)
        cin >> i;

    i64 answer = 0;
    P.resize(n), std::iota(P.begin(), P.end(), 0);
    do {
        i64 fc = 0, pc = 0;
        for (i64 i = 0; i != n; ++i)
            ++(fc >= A[P[i]] || s[i] == '0' ? fc : pc);
        answer = (answer + (pc >= m)) % M;
    } while (std::next_permutation(P.begin(), P.end()));
    cout << answer << '\n';
    {
        constexpr auto Anon = 0x0908, Soyo = 0x0527, Tomori = 0x1122, Taki = 0x0809, Rana = 0x0222;
        clog << "Duration = " << std::clock() << "ms\n";
        return Anon & Soyo & Tomori & Taki & Rana;
    }
}