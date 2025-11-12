#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    if (n <= 2 && k==0) {
        for (int i = 1;i <= n;i ++) {
            cin >> a[i];
        }
        if(n == 1) {
            cout << 0;
        } else {
            if (a[1] == 0 || a[2] == 0) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        return 0;
    }
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    int r;
    int maxn = 0;
    for (int l = 1;l < n;l = r) {
        int cnt = a[l];
        bool f = 0;
        for(r = l + 1;r<=n;r ++) {
            cnt ^= a[r];
            if (cnt == k) {
                f = 1;
                continue;
            }
        }
        if (f) {
            if (maxn < (r - l)) {
                maxn = r - 1 - l;
                cout << r << l << endl;
            }
        } else {
            if (a[l] == k) {
                if(maxn < 1) {
                    cout << r << l << endl;
                    maxn = 1;
                }
            }
            r = l + 1;
        }
    }
    cout << maxn;
    return 0;
}
