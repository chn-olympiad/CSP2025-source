#include <bits/stdc++.h>
#define int long long
using namespace std;
const int DIV = 998244353;

int n, cnt = 0;
int a[5050];
int maxx, sum;
// int ans[5050]; //DEL

signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= pow(2, n); i++) {
        // memset(ans, 0, sizeof(ans)); //DEL
        // int t = 0; //DEL
        maxx = 0;
        sum = 0;
        int x = i, j = 1;
        do {
            if (x % 2) {
                // ans[++t] = j; //DEL
                maxx = max(maxx, a[j]);
                sum += a[j];
            }
            j++;
        } while (x /= 2);
        if (maxx * 2 < sum) {
            cnt++;
            cnt %= DIV;
            // for (int i = 1; i <= t; i++) {
            //     cout << ans[i];
            // }
            // cout << "\n";
        }
    }
    cout << cnt % DIV;
    return 0;
}
