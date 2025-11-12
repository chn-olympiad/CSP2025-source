#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, m;
int c;
string s;
int sum;
signed main(void) {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i ++) cin >> c, sum += !c;
    if(n - sum < m) cout << 0 << endl;
    else {
        int ans = 1;
        for (int i = n; i > 1; i --) ans = ans * i % mod;
        cout << ans % mod;
    }
    return 0;
}
