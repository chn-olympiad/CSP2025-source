#include <bits/stdc++.h>
int main() {
    std::freopen("club.in", "r", stdin);
    std::freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::array<int, 3>> a(n);
        for (int i = 0; i < n; i++)
            std::cin >> a[i][0] >> a[i][1] >> a[i][2];
        std::vector<int> d(n);
        std::array<int, 3> b{};
        int s = 0;
        for (int i = 0; i < n; i++) {
            d[i] = std::max_element(a[i].begin(), a[i].end()) - a[i].begin();
            s += a[i][d[i]];
            b[d[i]]++;
        }
        std::vector<int> c;
        for (int i = 0; i < n; i++)
            if (b[d[i]] > n / 2)
                c.push_back(std::max(a[i][(d[i] + 1) % 3], a[i][(d[i] + 2) % 3]) - a[i][d[i]]);
        std::sort(c.begin(), c.end());
        while (c.size() > n / 2) {
            s += c.back();
            c.pop_back();
        }
        std::cout << s << '\n';
    }
    return 0;
}