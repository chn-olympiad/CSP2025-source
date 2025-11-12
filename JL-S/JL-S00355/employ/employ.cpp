#include <iostream>
#include <cstdio>
const int mod = 998244353;
int ans = 1;
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m, cnt = 0;
    std::cin >> n >> m;
    for (int i = n; ; i++) {
        ans = (ans * i) % mod;
        cnt++;
        if (cnt == m) break;
    }
    std::cout << ans << "\n";
    return 0;
}