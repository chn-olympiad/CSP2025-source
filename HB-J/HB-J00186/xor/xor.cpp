#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000100], xora[1000100];
bool check(int l, int r) {
    return k == (xora[r] xor xora[l - 1]);
}
int fastpow(int a, int b) {
    int ans = 1;
    for (;b ; b >>= 1, a = a * a)
        if (b & 1)
            ans *= a;
    return ans;
}
int main () {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xora[i] = xora[i - 1] xor a[i];
    }
    int ans = 0, xr = 1, l = 1;
    while (l <= n){
        while (xr <= n) {
            if (check(l, xr)) {
                ans++;
                l = xr + 1;
                xr = l;
                break;
            } else {
                xr++;
            }
        }
    }
    cout << ans;
    return 0;
}
