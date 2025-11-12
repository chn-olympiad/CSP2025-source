#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n;
const int mod = 998244353;
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n;
    cout << n % mod * (n - 1) % mod;
    return 0;
}
