//#include <RP++>
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 998244353;
int n, a[5005], sum, cnt;
bool cmp(int x, int y) {
    return x > y;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    for (int k = n - 1; k > -1; k--) {
        for (int i = k; i <= n; i++) {
            sum = 0;
            for (int j = 1; j <= i + k; j++) {
                sum = sum + a[j];
            }
            if (sum > 2 * a[i] && a[i] != a[k]) {
                cnt = (cnt + 1) % maxn;
            }
        }
    }
    cnt = cnt / 2;
    for (int k = 0; k < n; k++) {
        for (int i = 1; i <= n; i++) {
            sum = 0;
            for (int j = i + k; j <= n; j++) {
                sum = sum + a[j];
            }
            if (sum > 2 * a[i] && a[i] != a[k]) {
                cnt = (cnt + 1) % maxn;
            }
        }
    }
    cout << cnt;
    return 0;
}
