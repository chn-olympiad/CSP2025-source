#include <bits/stdc++.h>

namespace road {
    using i64 = std::int64_t;
    using u64 = std::uint64_t;
    
    constexpr auto operator""_uz(unsigned long long num) {
        return static_cast<std::size_t>(num);
    }

    std::ifstream fin("road.in");
    std::ofstream fout("road.out");

    std::size_t n, m, k;

    namespace UnionSetAlgorithm {
        auto get(std::vector<std::size_t> &us, std::size_t i) {
            auto &c = us[i];
            if (c == i) return i;
            return c = get(us, c);
        }

        inline auto merge(std::vector<std::size_t> &us, std::size_t u, std::size_t v) {
            u = get(us, u);
            v = get(us, v);

            if (u != v) {
                us[u] = v;
                return true;
            }

            return false;
        }
    }

    struct Road {
        std::size_t u;
        std::size_t v;
        u64 w;
    };

    std::vector<Road> edges;

    struct Extras {
        u64 c;
        u64 ws[10005];
    } extras[15];

    bool picked[15]{ };

    inline void main() {
        fin >> n >> m >> k;

        edges.reserve(m);

        for (auto i = 0_uz; i < m; ++i) {
            std::size_t u, v;
            u64 w;
            fin >> u >> v >> w;

            edges.push_back(Road{ --u, --v, w });
        }

        bool allzero = true;

        for (auto i = 0_uz; i < k; ++i) {
            auto &extra = extras[i];
            fin >> extra.c;

            if (extra.c) allzero = false;

            for (auto j = 0_uz; j < n; ++j) fin >> extra.ws[j];
        }
        if (allzero) {
            for (auto i = 0_uz; i < k; ++i) {
                const auto &extra = extras[i];
                const auto u = n + i;

                for (auto v = 0_uz; v < n; ++v) {
                    edges.push_back(Road{ u, v, extra.ws[v] });
                }
            }
        }

        std::vector<std::size_t> us(n + k);

        auto r = 0ull;

        const auto sorter = [](const Road &x, const Road &y) {
            return x.w < y.w;
        };

        std::iota(us.begin(), us.end(), 0_uz);
        std::sort(edges.begin(), edges.end(), sorter);

        for (const auto &edge : edges) {
            if (UnionSetAlgorithm::merge(us, edge.u, edge.v)) r += edge.w;
        }

        if (allzero) {
            fout << r;
            return;
        } // following are unchecked

        for (auto t = 0_uz; t < k; ++t) {
            auto mini = 0_uz;
            auto minr = 0xFFFF'FFFF'FFFF'FFFFull;
            for (auto i = 0_uz; i < k; ++i) {
                if (picked[i]) continue;
                std::vector<Road> edges1(edges.begin(), edges.end());

                const auto &extra = extras[i];
                const auto u = n + i;
                
                for (auto v = 0_uz; v < n; ++v) {
                    edges1.push_back(Road{ u, v, extra.ws[v] });
                }

                auto r1 = extra.c;

                std::iota(us.begin(), us.end(), 0_uz);
                std::sort(edges1.begin(), edges1.end(), sorter);

                for (const auto &edge : edges1) {
                    if (UnionSetAlgorithm::merge(us, edge.u, edge.v)) r1 += edge.w;
                }

                if (r1 < minr) {
                    mini = i;
                    minr = r1;
                }
            }

            if (minr >= r) break;

            picked[mini] = true;
            r = minr;

            const auto &extra = extras[mini];
            const auto u = n + mini;
            
            for (auto v = 0_uz; v < n; ++v) {
                edges.push_back(Road{ u, v, extra.ws[v] });
            }
        }

        fout << r;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    road::main();

    std::cout.flush();
    road::fout.flush();
    road::fout.close();
}