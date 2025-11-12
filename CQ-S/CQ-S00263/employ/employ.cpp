#include <bits/stdc++.h>
constexpr int mod = 998244353;
int main() {
    std::freopen("employ.in", "r", stdin);
    std::freopen("employ.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::string s;
    std::cin >> n >> m >> s;
    std::vector<int> c(n);
    for (int i = 0; i < n; i++)
        std::cin >> c[i];
    std::sort(c.begin(), c.end());
    std::vector<int> b(n);
    std::iota(b.begin(), b.end(), 0);
    int cnt = 0;
    do {
        int w = 0;
        for (int i = 0; i < n; i++)
            if (i - w < c[b[i]] && s[i] == '1')
                w++;
        if (w >= m)
            cnt++;
    } while (std::next_permutation(b.begin(), b.end()));
    std::cout << cnt << '\n';
    return 0;
}