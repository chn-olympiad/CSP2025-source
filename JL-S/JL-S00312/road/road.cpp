// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_SANITIZE_VECTOR 1
#include <bits/stdc++.h>
#define FILE_NAME "road"

using i32 = std::int32_t; using u32 = std::uint32_t;
using i64 = std::int64_t; using u64 = std::uint64_t;

/*
就是，最小生成树，但是，有若干条边，需要先点亮一个特殊节点，才可以连接。

K 很小。但是指数枚举还是远远不够。
怎么感觉还是可以贪心。
考虑点亮一个特殊节点可以获得多少收益。
首先，点亮他的价格是一个固定的支出。
接下来，计算从这个点到所有节点的最短路。
如果这个最短路，比不上这条直连道路，那样这条路就是稳赚不亏的。
如果总收益大于支出，就点亮它。
所以特殊节点的数量很少，因为从每个点开始都要跑一下最短路。

这就差不多了，但是时间复杂度，还是有一点危险。一秒？KQMlog(N)
我不知道啊。但就算过不去，分也不少，感觉也不是很难写。先实现一下吧。

坏了，好像有点想假了。

坏了，读错题了。城市和乡镇是独立计数的。也就是乡镇和乡镇不会进一步连边了。这好像稍微简单了一些。
先打一个暴力吧。枚举改造的城镇。

好消息是，除了MK都是满的数据以外，都能顺利通过。可以获得64分。
还能再凑一个性质分。如果所有的城镇改造都不花钱，可以直接最小生成树。这值8分。

64+8=72
*/
namespace Solution {
namespace {
    char constexpr endl = '\n';
    class DSU {
    public:
        std::vector<i32> pa, size;
        DSU(i32 n): pa(n + 1), size(n + 1, 1) {
            for (i32 i = 1; i <= n; ++i) pa[i] = i;
        }
        auto find(i32 u) -> i32 {
            if (pa[u] == u) return u;
            else return pa[u] = find(pa[u]);
        }
        auto add(i32 u, i32 v) -> void {
            if (size[pa[u]] < size[pa[v]]) std::swap(u, v);
            pa[pa[v]] = pa[u];
            size[u] += size[pa[v]];
        }
    };
    auto popcount(u32 x) -> i32 {
        return __builtin_popcount(x);
    }
    auto solve() -> void {
        i32 n, m, k; std::cin >> n >> m >> k;

        std::vector<std::array<i32, 3>> edges(m);
        for (auto &[len, x, y] : edges) {
            std::cin >> x >> y >> len;
        }
        std::sort(edges.begin(), edges.end());

        std::vector<i32> c(k + 1);
        std::vector<std::vector<i32>> add_cost(k + 1, std::vector<i32>(n + 1));
        bool all_free = true;
        for (i32 p = 1; p <= k; ++p) {
            std::cin >> c[p];
            if (c[p] != 0) all_free = false;
            for (i32 i = 1; i <= n; ++i) {
                std::cin >> add_cost[p][i];
            }
        }

        auto krusk = [&](std::vector<std::array<i32, 3>> const &final_edges, i32 n) -> i64 {
            DSU dsu{n + k};
            i64 cur_ans = 0;
            for (auto [len, u, v] : final_edges) {
                if (dsu.size[dsu.find(1)] == n) break;
                if (dsu.find(u) == dsu.find(v)) continue;
                dsu.add(u, v);
                cur_ans += len;
            }
            return cur_ans;
        };

        i64 ans = 0x3f3f3f3f3f3f3f3fLL;
        for (u32 st = 0; st != (1 << k); ++st) {
            if (all_free && st != (1 << k) - 1) continue;
            std::vector<std::array<i32, 3>> new_edges;
            auto sel = popcount(st);
            i64 ex_cost = 0;
            new_edges.reserve(sel * n);

            for (i32 i = 1; i <= k; ++i) {
                if ((1 << (i - 1)) & st) {
                    ex_cost += c[i];
                    for (i32 j = 1; j <= n; ++j) {
                        new_edges.push_back({add_cost[i][j], n + i, j});
                    }
                }
            }

            std::sort(new_edges.begin(), new_edges.end());

            std::vector<std::array<i32, 3>> final_edges(m + sel * n);
            std::merge(edges.begin(), edges.end(), new_edges.begin(), new_edges.end(), final_edges.begin());

            auto cur_ans = krusk(final_edges, n + sel);

            ans = std::min(ans, cur_ans + ex_cost);
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

    Solution::solve();

    return 0;
}