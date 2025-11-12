#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int a[114514];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    if (n < 3) {
        cout << 0;
        return 0;
    } if (n == 3) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b + c || b > a + c|| c > a + b) {
            cout << 0;
        } else {
            cout << 1;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 3; i <= n; i++) {
            int sum = 1;
            for (int j = 1; j <= i; j++)
                sum = (sum * (n - j + 1) / j) % MOD;
            ans += sum;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
