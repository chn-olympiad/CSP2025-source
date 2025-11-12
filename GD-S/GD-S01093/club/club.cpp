#include <bits/stdc++.h>

namespace club {
    using i64 = std::int64_t;
    using u64 = std::uint64_t;
    
    constexpr auto operator""_uz(unsigned long long num) {
        return static_cast<std::size_t>(num);
    }
    
    std::ifstream fin("club.in");
    std::ofstream fout("club.out");

    std::size_t t;
    std::size_t n;

    struct two {
        u64 a, b, c;
        u64 abmax;
        u64 bcmax;
        u64 camax;
    } inputs[100005_uz];
    
    inline void main() {
        fin >> t;

        std::vector<std::size_t> as;
        std::vector<std::size_t> bs;
        std::vector<std::size_t> cs;

        for (; t; --t) {
            fin >> n;

            const auto nhalf = n / 2_uz;

            as.reserve(nhalf);
            bs.reserve(nhalf);
            cs.reserve(nhalf);
            
            for (auto i = 0_uz; i < n; ++i) {
                auto &input = inputs[i];
                auto &ai = input.a;
                auto &bi = input.b;
                auto &ci = input.c;
                fin >> ai >> bi >> ci;

                input.abmax = std::max(ai, bi);
                input.bcmax = std::max(bi, ci);
                input.camax = std::max(ci, ai);

                if (ai <= bi) {
                    if (bi <= ci) cs.push_back(i);
                    else bs.push_back(i);
                } else {
                    if (ai <= ci) cs.push_back(i);
                    else as.push_back(i);
                }
            }

            if (as.size() > nhalf) {
                std::sort(as.begin(), as.end(), [&](const std::size_t &x, const std::size_t &y) {
                    const auto &xi = inputs[x];
                    const auto &yi = inputs[y];

                    return xi.bcmax + yi.a < yi.bcmax + xi.a;
                });

                do {
                    const auto last = *--as.end();
                    const auto &input = inputs[last];

                    if (input.b <= input.c) cs.push_back(last);
                    else bs.push_back(last);
                    as.pop_back();
                } while (as.size() > nhalf);
            }

            if (bs.size() > nhalf) {
                std::sort(bs.begin(), bs.end(), [&] (const std::size_t &x, const std::size_t &y) {
                    const auto &xi = inputs[x];
                    const auto &yi = inputs[y];

                    return xi.camax + yi.b < yi.camax + xi.b;
                });

                do {
                    const auto &last = *--bs.end();
                    const auto &input = inputs[last];

                    if (input.c <= input.a) as.push_back(last);
                    else cs.push_back(last);
                    bs.pop_back();
                } while (bs.size() > nhalf);
            }

            if (cs.size() > nhalf) {
                std::sort(cs.begin(), cs.end(), [&] (const std::size_t &x, const std::size_t &y) {
                    const auto &xi = inputs[x];
                    const auto &yi = inputs[y];

                    return xi.abmax + yi.c < yi.abmax + xi.c;
                });

                do {
                    const auto &last = *--cs.end();
                    const auto &input = inputs[last];

                    if (input.a <= input.b) bs.push_back(last);
                    else as.push_back(last);
                    cs.pop_back();
                } while (cs.size() > nhalf);
            }

            u64 r = 0;

            for (const auto &i : as) r += inputs[i].a;
            for (const auto &i : bs) r += inputs[i].b;
            for (const auto &i : cs) r += inputs[i].c;

            fout << r << '\n';

            as.clear();
            bs.clear();
            cs.clear();
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    
    club::main();

    std::cout.flush();
    club::fout.flush();
    club::fout.close();
}
