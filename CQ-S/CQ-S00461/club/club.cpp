#include <bits/stdc++.h>

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(false); std::cin.tie(0);

    int T; std::cin >> T; while (T--) {
        int n; std::cin >> n;
        std::vector<std::vector<int>> buc(3);
        std::vector<std::vector<int>> a(n + 1, std::vector<int>(3));
        int Ans = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i][0] >> a[i][1] >> a[i][2];
            int w = 0;
            if (a[i][1] > a[i][w]) { w = 1; }
            if (a[i][2] > a[i][w]) { w = 2; }
            buc[w].emplace_back(i); Ans += a[i][w];
        }
        
        int p = 0;
        if (buc[1].size() > buc[p].size()) { p = 1; }
        if (buc[2].size() > buc[p].size()) { p = 2; }
        if ((int)buc[p].size() > n / 2) {
            std::vector<int> val;
            for (auto i : buc[p]) {
                int w = 0;
                if (a[i][1] < a[i][w]) { w = 1; }
                if (a[i][2] < a[i][w]) { w = 2; }
                val.emplace_back(a[i][0] + a[i][1] + a[i][2] - 2 * a[i][p] - a[i][w]);
            }
            std::sort(val.begin(), val.end());
            for (int i = 1; i <= (int)buc[p].size() - n / 2; i++) {
                Ans += val.back(); val.pop_back();
            }
        }
        std::cout << Ans << '\n';
    }

    return 0;
}