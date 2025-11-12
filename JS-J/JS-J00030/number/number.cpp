#include <bits/stdc++.h>
#define int long long
std::string s;
int a[15];
signed main() {
    std::freopen("number.in", "r", stdin), std::freopen("number.out", "w", stdout);
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cin >> s;
    for (auto i : s)
        if (i >= '0' && i <= '9')
            ++a[i - '0'];
    for (int i = 9; i >= 0; --i)
        for (int j = 1; j <= a[i]; ++j)
            std::cout << i;
    return 0;
}
