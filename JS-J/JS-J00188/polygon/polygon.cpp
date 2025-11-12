#include<bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 998244353;
int a[N];
int c[N][N];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    bool flag = true;
    for (int i= 1;i <= n; i++) {
        cin >> a[i];
        if (a[i] > 1) {
            flag = false;
        }
    }
    if (flag) {
        c[1][0] = c[1][1] = 1;
        for (int i = 2; i <= n;i ++) {
            c[i][0] = 1;
            for (int j = 1; j<= i; j++) {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
                c[i][j] %= mod;
            }
        }
        int ans = 0;
        for (int i = 3;i <= n; i++) {
            ans += c[n][i];
            ans %= mod;
        }
        cout << ans;
        return 0;
    }
        int ans = 0;
        for (int i = 0; i <  (1 << n);i++) {
            int cnt = 0;
            int x = i;
            int mx = -1, sum = 0;
            for (int j = 1; j <= n; j++) {
                if (((x >> (j - 1)) & 1) == 1) {
                    cnt++;
                    mx = max(mx, a[j]);
                    sum += a[j];
                }
            }
            if (cnt < 3) {
                continue;
            }
            if (sum > mx * 2) {
                ans++;
            }
        }
        cout << ans % mod;
    return 0;
}
