#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, cnt = 0;
int a[500050];
int b[500050];
int last;

signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] ^ b[i - 1];
    }

    last = n + 1;
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= i; j--) {
            // cout << i << " " << j << " " << (b[i - 1] ^ b[j]) << "\n";
            if ((b[i - 1] ^ b[j]) == k && j < last) {
                cnt++;
                last = i;
            }
        }
    }
    cout << cnt;
    return 0;
}
