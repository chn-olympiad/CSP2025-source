#include <iostream>
#include <cstring>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (m == n) {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '1') {
                cout << 0;
                return 0;
            }
        }
        int ans = 1;
        for (int j = 1; j <= n; j++) {
            ans = ans * j % mod;
        }
        cout << ans << endl;
    }
    int ans = 0;
    for (int i = m; i <= n; i++) {
        int Ans = 1;
        //Ans = congngexuanige
        for (int j = n - m + 1; j <= n; j++) Ans = Ans * j % mod;
        ans = (ans + Ans) % mod;
    }
    cout << ans << endl;
    return 0;
}
