#include <bits/stdc++.h>
#define FILE_NAME "replace"


using i32 = std::int32_t; using u32 = std::uint32_t;
using i64 = std::int64_t; using u64 = std::uint64_t;

/*
看起来这个题的 B 性质也很好写。
待会来拼一拼。

预处理一下，字母B左右的，A的数量
然后是一个二维偏序，计数：
x.la <= la
x.ra <= ra
x.ra - x.la = ra - la

唉写一下暴力。
好像哈希一下就可以了？

我在做什么！这个匹配似乎完全可以logN以内的复杂度解决。
所以A性质的分也是可以得到的。
我的天呐。好智慧。暴力和A性质分拿到。不过需要求逆元，改用双mod哈希。
25+10+25=55
*/
namespace Solution {
namespace {
    char constexpr endl = '\n';
    class BIT {
        struct Node {
            i32 val = 0, time = 0;
        };
        i32 now = 0;
        std::vector<Node> c;

        auto static constexpr lowbit(i32 x) -> i32 { return x & -x; }
    public:
        BIT(i32 n) : c(n + 1) {}

        auto add_at(i32 x, i32 val) -> void {
            ++x;
            while (x < (i32)c.size()) {
                if (c[x].time != now) c[x] = {0, now};
                c[x].val += val;
                x += lowbit(x);
            }
        }
        auto sum_pre(i32 x) -> i32 {
            ++x;
            i32 sum = 0;
            while (x != 0) {
                if (c[x].time != now) c[x] = {0, now};
                sum += c[x].val;
                x -= lowbit(x);
            }
            return sum;
        }
        auto clear() -> void { ++now; }
    };
    auto constexpr qpow(i64 a, i64 b, u32 mod) -> u32 {
        i64 res = 1;
        for (; b != 0; b >>= 1, a = a * a % mod) {
            if (b & 1) res = res * a % mod;
        }
        return res;
    }
    i32 constexpr p0 = 998'244'353, p1 = 1'000'000'007, base = 131;
    using hashed = std::array<i32, 2>;
    auto operator- (hashed a, hashed b) -> hashed {
        return {(a[0] - b[0] + p0) % p0, (a[1] - b[1] + p1) % p1};
    }
    auto solve_force(i32 n, i32 q) -> void {

        auto hash = [&](std::string const &s) -> hashed {
            u64 res0 = 0, res1 = 0, tmp0 = 1, tmp1 = 1;
            for (auto ch : s) {
                res0 += ch * tmp0, res0 %= p0;
                res1 += ch * tmp1, res1 %= p1;
                tmp0 *= base, tmp0 %= p0;
                tmp1 *= base, tmp1 %= p1;
            }
            return {(i32)res0, (i32)res1};
        };

        std::vector<std::pair<hashed, i32>> a(n);
        for (i32 i = 0; i < n; ++i) {
            std::string s1, s2;
            std::cin >> s1 >> s2;
            a[i] = std::make_pair(hash(s2) - hash(s1), (i32)s1.size());
        }

        std::sort(a.begin(), a.end());

        for (i32 i = 0; i < q; ++i) {
            std::string s1, s2;
            std::cin >> s1 >> s2;

            auto q_len = (i32)s1.size();

            i64 ans = 0;
            auto t1 = hash(s1), t2 = hash(s2);
            hashed tmp{1, 1};

            for (i32 j = 0; j < q_len; ++j) {
                i32 max_len = q_len - j;
                u32 h0 = i64((t2[0] - t1[0] + p0) % p0) * qpow(tmp[0], p0 - 2, p0) % p0;
                u32 h1 = i64((t2[1] - t1[1] + p1) % p1) * qpow(tmp[1], p1 - 2, p1) % p1;

                auto to_find = hashed{h0, h1};
                auto it0 = std::lower_bound(a.begin(), a.end(), std::make_pair(to_find, 0));
                auto it1 = std::upper_bound(a.begin(), a.end(), std::make_pair(to_find, max_len));

                ans += it1 - it0;

                tmp[0] = i64(tmp[0]) * base % p0;
                tmp[1] = i64(tmp[1]) * base % p1;
            }

            std::cout << ans << endl;
        }
    }
    auto solve() -> void {
        i32 n, q;
        std::cin >> n >> q;

        if (n <= 100 || q <= 1) return solve_force(n, q);

        struct Item {
            i32 la, ra, diff = 0;

            auto operator< (Item const &y) const -> bool {
                auto const &x = *this;
                if (x.diff != y.diff) return x.diff < y.diff;
                if (x.la != y.la) return x.la < y.la;
                return x.ra < y.ra;
            }
        };
        std::vector<Item> a(n);
        std::vector<std::pair<Item, i32>> qs(q);

        {
            auto findb = [&](std::string const &s) -> i32 {
                auto pos = s.find('b');
                if (pos == s.npos) return (i32)s.size();
                else return pos;
            };

            auto cmp2str = [&](std::string const &s1, std::string const &s2) -> Item {
                auto f1 = findb(s1);
                auto f2 = findb(s2);

                auto diff = f2 - f1;
                return {f1, (i32)s1.size() - f1 - 1, diff};
            };

            for (auto &x : a) {
                std::string s1, s2;
                std::cin >> s1 >> s2;
                x = cmp2str(s1, s2);
            }

            for (i32 i = 0; i < q; ++i) {
                std::string s1, s2;
                std::cin >> s1 >> s2;
                qs[i] = {cmp2str(s1, s2), i};
            }
        }

        std::sort(qs.begin(), qs.end());
        std::sort(a.begin(), a.end());

        i32 constexpr max_ra = 1e7;
        BIT bit{max_ra};

        i32 prev_diff = -0x3f3f3f3f;
        i32 j = 0;
        std::vector<i32> ans(q);
        for (i32 i = 0; i < q; ++i) {
            auto [la, ra, diff] = qs[i].first;
            auto index = qs[i].second;
            if (diff != prev_diff) {
                bit.clear();
                while (j != n && a[j].diff < diff) ++j;
                prev_diff = diff;
            }

            while (j != n && a[j].diff == diff && a[j].la <= la) {
                bit.add_at(a[j].ra, 1);
                ++j;
            }

            ans[index] = bit.sum_pre(ra);
        }

        for (i32 i = 0; i < q; ++i) {
            std::cout << ans[i] << endl;
        }
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