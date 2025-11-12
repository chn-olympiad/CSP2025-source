#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500010];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "W", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int fal = 1, flg = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] != fal) {
            flg = true;
            break;
        }
    }
    if (!flg) {
        if (n % 2 == 1) {
            cout << n - 2;
        } else {
            cout << n;
        }
    } else {
        //0 -> 奇数， 1 -> 偶数 k = 0, n - 1
        int zero = 0, one = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) zero++;
            if (a[i] == 1) one++;
        }
        if (zero % 2 == 1 && one % 2 == 0 && k == 0) {
            int t = zero / 2;
            if (t % 2 == 1) cout << n;
            else cout << n - 1;
        }
        if (zero % 2 == 0 && one % 2 == 0 && k == 0) {
            cout << n;
        }
    }
    return 0;
}
