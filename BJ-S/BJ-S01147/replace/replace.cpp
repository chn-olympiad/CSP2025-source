#include <bits/stdc++.h>
#include <bits/extc++.h>

namespace {
    using i64 = decltype(1ll);
    using std::cin; using std::cout; using std::cerr; using std::clog;
    
    i64 n, q;
    std::string x, y;
    std::set<std::string> S;
}

auto main() -> int {
    #define FILE "replace"
    std::freopen(FILE".in", "r", stdin), std::freopen(FILE".out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;

    for (i64 i = 0; i != n; ++i) {
        cin >> x >> y;
        S.insert(x + " # " + y);
    }

    while (q--) {
        cin >> x >> y;
        if (x.size() != y.size()) {
            cout << "0\n";
        } else {
            i64 m = std::min(x.size(), y.size());
            i64 answer = 0;

            for (i64 i = 0; i != m; ++i) {
                for (i64 j = 0; j != m; ++j) {
                    answer += S.count(x.substr(i, x.size() - j - i) + " # " + y.substr(i, y.size() - j - i));
                    if (x[x.size() - j - 1] != y[y.size() - j - 1])
                        break;
                }
                if (x[i] != y[i])
                    break;
            }
            
            cout << answer << '\n';
        }
    }
    {
        constexpr auto Anon = 0x0908, Soyo = 0x0527, Tomori = 0x1122, Taki = 0x0809, Rana = 0x0222;
        clog << "Duration = " << std::clock() << "ms\n";
        return Anon & Soyo & Tomori & Taki & Rana;
    }
}