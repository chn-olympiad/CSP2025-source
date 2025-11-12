#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;
const i64 MAXN = 2e5 + 10;
i64 n, q;
std::string s1[MAXN], s2[MAXN], t1[MAXN], t2[MAXN];

namespace sol_b {
    bool check(void) {
        auto check2 = [&] (const std::string& a, const std::string& b) -> bool {
            for (char ch : a) {
                if (ch != 'a' && ch != 'b') return false;
            }
            for (char ch : b) {
                if (ch != 'a' && ch != 'b') return false;
            }
            i64 cnt = 0;
            for (char ch : a) {
                if (ch == 'b') ++cnt;
            }
            if (cnt != 1) return false;
            cnt = 0;
            for (char ch : b) {
                if (ch == 'b') ++cnt;
            }
            if (cnt != 1) return false;
            return true;
        };
        for (i64 i = 1; i <= n; ++i) {
            if (!check2(s1[i], s2[i])) return false;
        }
        for (i64 i = 1; i <= q; ++i) {
            if (!check2(t1[i], t2[i])) return false;
        }
        return true;
    }

    using PLL = std::pair<i64, i64>;
    const i64 MAXM = 1e7 + 10, ADD = 5e6 + 3;
    std::map<i64, std::vector<i64>> cnt[MAXM];

    void solve(void) {
        for (i64 i = 1; i <= n; ++i) {
            i64 p1 = 0, p2 = 0;
            for (i64 j = 0; j < (i64) s1[i].size(); ++j) {
                if (s1[i][j] == 'b') {
                    p1 = j;
                    break;
                }
            }
            for (i64 j = 0; j < (i64) s2[i].size(); ++j) {
                if (s2[i][j] == 'b') {
                    p2 = j;
                    break;
                }
            }
            cnt[p2 - p1 + ADD][std::min(p1, p2)].emplace_back((i64) s1[i].size() - std::max(p1, p2));
//            std::cout << p2 - p1 << ' ' << std::min(p1, p2) << ' ' << (i64) s1[i].size() - std::max(p1, p2) << '\n';
        }
        for (i64 i = 0; i < MAXM; ++i) if (cnt[i].size()) {
            for (auto& x : cnt[i]) {
                std::sort(x.second.begin(), x.second.end());
            }
        }
        for (i64 i = 1; i <= q; ++i) {
            i64 p1 = 0, p2 = 0;
            for (i64 j = 0; j < (i64) t1[i].size(); ++j) {
                if (t1[i][j] == 'b') {
                    p1 = j;
                    break;
                }
            }
            for (i64 j = 0; j < (i64) t2[i].size(); ++j) {
                if (t2[i][j] == 'b') {
                    p2 = j;
                    break;
                }
            }
//            std::cerr << p2 - p1 << '\n';
//            std::cout << cnt[p2 - p1] << '\n';
            i64 ans = 0;
            for (i64 j = 0; j <= std::min(p1, p2); ++j) {
                auto& v = cnt[p2 - p1 + ADD][j];
                ans += std::upper_bound(v.begin(), v.end(), (i64) t1[i].size() - std::max(p1, p2)) - v.begin();
            }
            std::cout << ans << '\n';
        }
    }
}

namespace sol_bf {
    using VL = std::vector<i64>;
    void get_nxt(const std::string s, VL& nxt) {
        nxt.clear();
        nxt.resize(s.size());
        for (i64 i = 1; i < (i64) s.size(); ++i) {
            nxt[i] = nxt[i - 1];
            while (nxt[i] && s[nxt[i]] != s[i]) nxt[i] = nxt[nxt[i] - 1];
            if (s[nxt[i]] == s[i]) ++nxt[i];
        }
    }
    const i64 INF = 0x3f3f3f3f3f3f3f3f;
    i64 calc(i64 i) {
        i64 minn = INF, maxn = 0;
        for (i64 j = 0; j < (i64) t1[i].size(); ++j) {
            if (t1[i][j] != t2[i][j]) {
                minn = std::min(minn, j);
                maxn = std::max(maxn, j);
            }
        }
        i64 ans = 0;
        for (i64 j = 1; j <= n; ++j) {
            if ((i64) s1[j].size() < maxn - minn + 1) continue;
            std::string k1 = s1[j] + '#' + t1[i];
            std::string k2 = s2[j] + '#' + t2[i];
            VL nxt1, nxt2;
            get_nxt(k1, nxt1);
            get_nxt(k2, nxt2);
            for (i64 k = 0; k < (i64) t1[i].size(); ++k) {
                if (k - (i64) s1[j].size() + 1 <= minn && k >= maxn && nxt1[k + (i64) s1[j].size() + 1] == (i64) s1[j].size() && nxt2[k + (i64) s1[j].size() + 1] == (i64) s2[j].size()) {
                    ++ans;
                }
            }
        }
        return ans;
    }
    void solve(void) {
        for (i64 i = 1; i <= q; ++i) {
            std::cout << calc(i) << '\n';
        }
    }
}

void solve(void) {
    std::cin >> n >> q;
    for (i64 i = 1; i <= n; ++i) {
        std::cin >> s1[i] >> s2[i];
    }
    for (i64 i = 1; i <= q; ++i) {
        std::cin >> t1[i] >> t2[i];
    }
    if (sol_b::check()) {
        sol_b::solve();
    }
    else {
        sol_bf::solve();
    }
}

int main() {
    IG = freopen("replace.in", "r", stdin);
    IG = freopen("replace.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}
