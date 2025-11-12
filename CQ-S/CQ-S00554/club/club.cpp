#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::freopen("club.in", "r", stdin);
    std::freopen("club.out", "w", stdout);
    auto stime = std::chrono::steady_clock::now();
    int T;
    for (std::cin >> T; T--; ) {
        int n, res = 0;
        std::cin >> n;
        std::vector<std::vector<int> > pos(3);
        std::vector<std::array<int, 3> > a(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i][0] >> a[i][1] >> a[i][2];
            int k = std::max_element(a[i].begin(), a[i].end()) - a[i].begin();
            pos[k].push_back(i), res += a[i][k];
        }
        int k = -1;
        if ((int)pos[0].size() > n / 2)
            k = 0;
        else if ((int)pos[1].size() > n / 2)
            k = 1;
        else if ((int)pos[2].size() > n / 2)
            k = 2;
        if (k != -1) {
            std::vector<int> p;
            for (auto i : pos[k]) {
                int now = 0x3f3f3f3f;
                for (int j = 0; j < 3; ++j)
                    if (j != k)
                        now = std::min(now, a[i][k] - a[i][j]);
                p.push_back(now);
            }
            std::sort(p.begin(), p.end());
            for (int i = 1; i <= (int)pos[k].size() - n / 2; ++i)
                res -= p[i - 1];
        }
        std::cout << res << '\n';
    }
    std::cerr << std::fixed << std::setprecision(6) << std::chrono::duration<double>(std::chrono::steady_clock::now() - stime).count() << "s\n";
    return 0;
}
/*
首先，所有人取自己的 max
要么直接合法，要么有一种 >n/2
对于 >n/2 的，删去多余部分即可……
*/