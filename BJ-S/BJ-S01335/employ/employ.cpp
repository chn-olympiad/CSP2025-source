#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, ans = 1;
    cin >> n;
    for(int i = 1; i <= n; i++) ans = (ans * i) % mod;
    cout << ans;
    return 0;
}
