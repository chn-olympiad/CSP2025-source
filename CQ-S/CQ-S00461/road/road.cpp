#include <bits/stdc++.h>

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int n, m, k; std::cin >> n >> m >> k;
    std::vector<std::tuple<int, int, int>> road(m + k * n + 1);
    for (int i = 1; i <= m; i++) {
        std::cin >> std::get<1>(road[i]) >> std::get<2>(road[i]) >> std::get<0>(road[i]);
    }
    std::vector<std::vector<int>> ext(k + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) { std::cin >> ext[i][j]; }
        for (int j = 1; j <= n; j++) { road[m + (i - 1) * n + j] = {ext[i][j], n + i, j}; }
    }
    std::sort(next(road.begin()), road.end());

    long long Ans = 0;
    std::vector<int> Fr(n + k + 1);
    std::function<int(int)> GetFa = [&](int x) {
        return Fr[x] == x ? x : Fr[x] = GetFa(Fr[x]);
    };
    std::iota(Fr.begin() + 1, Fr.begin() + n + 1, 1);
    std::vector<std::tuple<int, int, int>> ROAD;
    for (auto i : road) {
        int x = std::get<1>(i), y = std::get<2>(i);
        if (x > n) { ROAD.emplace_back(i); }
        if (x > n || GetFa(x) == GetFa(y)) { continue; }
        ROAD.emplace_back(i);
        Ans += std::get<0>(i); Fr[GetFa(x)] = GetFa(y);
    }
    for (int s = 1; s < (1 << k); s++) {
        long long tmp = 0;
        for (int i = 1; i <= k; i++) {
            if ((s >> (i - 1)) & 1) { tmp += ext[i][0]; }
        }
        std::iota(Fr.begin() + 1, Fr.begin() + n + k + 1, 1);
        for (auto i : ROAD) {
            int x = std::get<1>(i), y = std::get<2>(i);
            if (x > n && !((s >> (x - n - 1)) & 1)) { continue; }
            if (GetFa(x) == GetFa(y)) { continue; }
            tmp += std::get<0>(i); Fr[GetFa(x)] = GetFa(y);
        }
        Ans = std::min(Ans, tmp);
    }
    std::cout << Ans << '\n';

    return 0;
}