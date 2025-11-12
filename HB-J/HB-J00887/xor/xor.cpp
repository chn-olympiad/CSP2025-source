#include <bits/stdc++.h>
using namespace std;
int n, k, a[(int)(5*1e5)];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < sizeof(a) / sizeof(int); i++) cin >> a[i];
    if (k == 0) {
        if (n == 1) {
            if (a[0] == 0) cout << 1;
            else cout << 0;
        } else if (n == 2) {
            if (a[0] == a[1]) cout << 1;
            else cout << 0;
        } else {
            int xor_counter = 0, xor_counter_max = 0, xor_tmp = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    xor_tmp ^= a[i];
                    if (xor_tmp == k) {
                        xor_counter_max++;
                        xor_tmp = 0;
                    }
                }
                xor_counter = max(xor_counter, xor_counter_max);
                xor_counter_max = 0;
            }
            cout << xor_counter;
        }
    } else {
        int xor_counter = 0, xor_tmp = 0;
        for (int i = 0; i < n; i++) {
            xor_tmp ^= a[i];
            if (xor_tmp == k) {
                xor_counter++;
                xor_tmp = 0;
            }
        }
        cout << xor_counter;
    }
    return 0;
}
