#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5+5;
const int Mod = 998244353;
int n, q;
int calc(int n) {
    int res = 1;
    for(int i = 1; i <= n; i++) {
        res *= i; res %= Mod;
    } return res;
}
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> q;
    if(q != n) cout << calc(n) << endl;
    else if(q == n) cout << 0 << endl;
    return 0;
}
