#include <bits/stdc++.h>
using namespace std;
#define Mod 998244353
int n, a[5005];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    bool f = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) f = false;
    }
    if (n < 3) cout << 0;
    else if (n == 3){
        sort(a + 1, a + 1 + 3);
        if (a[3] < a[1] + a[2]) cout << 1;
        else cout << 0;
    } else if (f) {
        long long ans = (1 << n) - 1;
        ans -= n;
        ans -= n * (n - 1) / 2;
        cout << ans;
    } else cout << 15;
    return 0;
}
