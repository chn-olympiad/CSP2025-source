#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, cnt = 0;
vector<int> a;
signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (__int128 p = 0; p <= (1 << __int128(n)); p++) {
        int maxlength = 0, edgecount = 0;
        __int128 sumlength = 0;
        for (__int128 i = 0; i < n; i++) {
            if (p & (1 << i)) {
                maxlength = max(maxlength, a[i]);
                sumlength += a[i];
                ++ edgecount;
            }
        }
        if (sumlength > maxlength * 2 && edgecount >= 3) {
            ++ cnt;
            cnt %= mod;
        }
    }
    cout << (cnt % mod) << "\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}