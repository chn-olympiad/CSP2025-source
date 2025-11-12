#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k;
int a[N];
int ans;
void solve () {
    for (int i = 1; i <= n; i++) {
        if (a[i] == k) continue;
        int maxx = 0, k_i = i + 1;
        for (int j = i; j <= n; j++) {
            if (a[j] == k) {
                k_i = j;
                break;
            }
            int sum = 0, x = a[j];
            for (int l = j + 1; l <= n; l++) {
                if (a[l] == k) break;
                x = x ^ a[l];
                if (x == k) {
                    ++ sum;
                    x = 0;
                }
            }
            maxx = max (maxx, sum);
        }
        i = k_i;
        ans += maxx;
    }
}
int main () {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie (0), cout.tie (0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == k) {
            ++ ans;
        }
    }
    if (k <= 1) {
        if (k == 0) {
            if (a[1] == 0) {
                ans = n;
            } else {
                ans = n / 2;
            }
        } else {
            if (a[1] == 1) {
                ans = n;
            }
        }
    } else solve ();
    cout << ans << "\n";
    return 0;
}
/*

yxy i like you.

*/
