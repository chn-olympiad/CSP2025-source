#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::freopen("road.in", "r", stdin);
    std::freopen("road.out", "w", stdout);
    auto stime = std::chrono::steady_clock::now();
    int n, m, k, tot = 0;
    std::cin >> n >> m >> k;
    auto res = 0ll;
    using edge = std::tuple<int, int, int>;
    std::vector<edge> e1, e;
    std::vector<int> c(k + 1);
    std::vector<std::vector<edge> > u(k + 1);
    for (int x, y, w; tot < m; ++tot) {
        std::cin >> x >> y >> w;
        e1.emplace_back(w, x, y);
    }
    std::sort(e1.begin(), e1.end());
    for (int i = 1; i <= k; ++i) {
        std::cin >> c[i];
        for (int j = 1, w; j <= n; ++j, ++tot) {
            std::cin >> w;
            u[i].emplace_back(w, n + i, j);
        }
        std::sort(u[i].begin(), u[i].end());
    }
    std::vector<int> f(n + k + 1), siz(n + k + 1, 1);
    std::iota(f.begin() + 1, f.end(), 1);
    std::function<int(int)> find = [&](int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    };
    auto merge = [&](int x, int y) {
        x = find(x), y = find(y);
        // 按秩合并真的能和路径压缩一起写吗？
        // 不清楚。故写启发式。
        if (x != y) {
            if (siz[x] < siz[y])
                f[x] = y, siz[y] += siz[x];
            else
                f[y] = x, siz[x] += siz[y];
        }
        return;
    };
    for (auto [w, x, y] : e1)
        if (find(x) != find(y)) {
            merge(x, y), res += w;
            e.emplace_back(w, x, y);
        }
    e1.resize(n + n * k);
    std::vector<edge> tmp(n + n * k);
    for (int j = 1; j < (1 << k); ++j) {
        std::copy(e.begin(), e.end(), e1.begin());
        int now = n;
        auto s = 0ll;
        for (int i = 1; i <= k; ++i)
            if ((j >> (i - 1)) & 1) {
                s += c[i];
                std::merge(e1.begin(), e1.begin() + now, u[i].begin(), u[i].end(), tmp.begin());
                now += n;
                std::copy(tmp.begin(), tmp.begin() + now, e1.begin());
            }
        std::iota(f.begin() + 1, f.end(), 1);
        std::fill(siz.begin() + 1, siz.end(), 1);
        for (int i = 0; i < now; ++i) {
            auto &[w, x, y] = e1[i];
            if (find(x) != find(y))
                merge(x, y), s += w;
        }
        res = std::min(res, s);
    }
    std::cout << res << '\n';
    std::cerr << std::fixed << std::setprecision(6) << std::chrono::duration<double>(std::chrono::steady_clock::now() - stime).count() << "s\n";
    return 0;
}
/*
k = 0，跑生成树即可
k /ne 0，状压 + 生成树显然会起飞

有办法证明能够只选一个来城市化吗
似乎不行

啧，好像有点低烧

1e7 也跑得动啊。
bb: 其实是 1e8。但跑不满就是了。
因为有用的只有树边，归并即可。
*/