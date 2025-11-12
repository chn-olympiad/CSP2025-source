#include<bits/stdc++.h>
#define int long long
const int mod = 998244353;
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, ans = 1;
    std::cin >> n;
    for(int i = 2; i <= n; i++) ans = (ans * n) % mod;
    std::cout << ans;
}
