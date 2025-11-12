#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;
using u128 = unsigned __int128;

using vi = std::vector<int> ;
using vI = std::vector<i64> ;
using str = std::string;

constexpr int N = 1005;

int n, q;

str s[N][2], t[N][2];

u64 pw[N], bs = 131;

struct hsh {
    u64 hs[N];
    inline void init(str &s) {
        for (int i = 1; i < s.size(); i++) {
            hs[i] = hs[i - 1] * bs + s[i];
        }
    }
    inline u64 qry(int l, int r) {
        return hs[r] - hs[l - 1] * pw[r - l + 1];
    }
} ha[N];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    pw[0] = 1;
    for (int i = 1; i <= N - 5; i++) {
        pw[i] = pw[i - 1] * bs;
    }

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i][0] >> s[i][1];
        str ss = ' ' + s[i][0];
        ha[i].init(ss);
    }
    for (int i = 1; i <= q; i++) {
        std::cin >> t[i][0] >> t[i][1];
        if (n >= 1000 && q >= 1000) {
            std::cout << 0 << '\n';
            continue;
        }
        hsh fw;
        str ss = ' ' + t[i][0];
        fw.init(ss);
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            if (s[j][0].size() > t[i][0].size()) {
                continue;
            }
            for (int k = 0; k + s[j][0].size() - 1 < t[i][0].size(); k++) {
                if (ha[j].qry(1, s[j][0].size()) == fw.qry(k + 1, k + s[j][0].size())) {
                    if (t[i][0].substr(0, k) + s[j][1] + t[i][0].substr(k + s[j][0].size(), t[i][0].size() - k - s[j][0].size()) == t[i][1]) {
                        ans++;
                    }
                    // std::cerr << t[i][0].substr(0, k) + s[j][1] + t[i][0].substr(k + s[j][0].size(), t[i][0].size() - k - s[j][0].size()) << '\n';
                }
            }
        }
        std::cout << ans << '\n';
    }

    return (0 ^ 0);
}