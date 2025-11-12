#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, a[10005], sum[5005], ans;

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i] + a[i];
    }
    for (int i = 3; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (sum[j] - sum[j-i] > 2 * a[i+j-1]) {
                ans++;
                ans %= 998244353;
            }
        }
    }
    cout << ans;
    return 0;
}
