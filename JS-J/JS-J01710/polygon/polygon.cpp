#include <bits/stdc++.h>
using namespace std;

int n, sum, maxv;
int a[5005];

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1;i <= n; i++){
        for (int j = i + 2; j <= n; j++){
            sum = 0;
            maxv = -1e6;
            for (int k = i; k <= j; k++){
                sum += a[k];
                maxv = max(maxv, a[k]);
            }
            if (sum > maxv * 2) {
                cout << sum << " " << maxv << endl;
                ans++;
                ans %= 998244353;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
