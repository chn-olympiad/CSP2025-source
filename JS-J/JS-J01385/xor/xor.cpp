#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
long long a[110];
int vis[110];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    int n;
    long long k;
    cin >> n >> k;
    int f = 0, f1 = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) {
            f = 1;
        }
        if (a[i] != 0 && a[i] != 1) {
            f1 = 1;
        }
        if (a[i] == 1) {
            cnt1++;
        }
        if (a[i] == 0) {
            cnt2++;
        }
    }
    if (f == 0) {
        if (k > 1) {
            cout << 0;
        } else if (k == 1) {
            cout << n;
        } else if (k == 0) {
            cout << n / 2;
        }
        return 0;
    }
    if (f1 == 0) {
        if (k > 1) {
            cout << 0;
        } else if (k == 0) {
            cout << cnt2;
        } else if (k == 1) {
            cout << cnt1;
        }
        return 0;
    }
    int cnt = 0;
    int l = 1, r = 1;
    while (l <= n) {
        long long ret = a[l];
        for (int i = l + 1; i <= r; i++) {
            ret ^= a[i];
        }
        if (ret == k) {
            for (int i = l; i <= r; i++) {
                vis[i] = 1;
            }
            cnt++;
            r++;
            l = r;
        } else {
            r++;
            if (r > n) {
                l++;
                r = l;
            }
        }
    }
    cout << cnt;


    return 0;
}
