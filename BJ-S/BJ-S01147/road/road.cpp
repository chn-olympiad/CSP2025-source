#include <bits/stdc++.h>
#include <bits/extc++.h>

namespace {
    using i64 = decltype(1ll);
    using std::cin; using std::cout; using std::cerr; using std::clog;

    i64 n, m, k;
    std::vector<i64> C, D;
    std::vector<std::vector<i64>> A;
    std::vector<std::pair<std::pair<i64, i64>, i64>> oedges, nedges;

    auto root(i64 i) -> i64 {
        return D[i] == i ? i : D[i] = root(D[i]);
    }
}

auto main() -> int {
    #define FILE "road"
    std::freopen(FILE".in", "r", stdin), std::freopen(FILE".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> k;

    oedges.resize(m);
    for (auto& i : oedges)
        cin >> i.first.first >> i.first.second >> i.second;

    C.resize(k + 1), A.resize(k + 1, std::vector<i64>(n + 1));
    for (i64 i = 1; i <= k; ++i) {
        cin >> C[i];
        for (i64 j = 1; j <= n; ++j)
            cin >> A[i][j];
    }

    i64 answer = 1e18;
    for (i64 choice = (std::count(C.begin(), C.end(), 0) == C.size() ? (1 << k) - 1 : 0); choice != 1 << k && std::clock() < 9e5; ++choice) {
        i64 sum = 0;

        nedges = oedges;
        for (i64 i = 1; i <= k; ++i)
            if ((choice >> (i - 1)) & 1)
                for (i64 j = (sum += C[i], 1); j <= n; ++j)
                    nedges.emplace_back(std::make_pair(n + i, j), A[i][j]);

        std::sort(nedges.begin(), nedges.end(), [&](auto& x, auto& y) { return x.second < y.second; });
        D.resize(n + k + 1), std::iota(D.begin(), D.end(), 0);

        for (auto i : nedges) {
            i64 u = root(i.first.first), v = root(i.first.second), w = i.second;
            u != v && (D[u] = v, (sum += w));
        }

        answer = std::min(answer, sum);
    }
    cout << answer << '\n';
    {
        constexpr auto Anon = 0x0908, Soyo = 0x0527, Tomori = 0x1122, Taki = 0x0809, Rana = 0x0222;
        clog << "Duration = " << std::clock() << "ms\n";
        return Anon & Soyo & Tomori & Taki & Rana;
    }
}