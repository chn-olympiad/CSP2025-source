#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a[n];
    bool one = true, zero_or_one = true;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i] != 1) {
            one = false;
        }
        if (a[i] != 0 && a[i] != 1) {
            zero_or_one = false;
        }
    }
    if (one) {
        if (k == 1)
            cout << n / 3 << endl;
        else
            cout << n / 2 << endl;
        return 0;
    }
    else if (zero_or_one) {
        bool p[100010];
        memset(p, false, sizeof(p));
        int cnt = 0;
        for (int i = 1; i < n; i ++) {
            if ((a[i] ^ a[i - 1]) == k && p[i] == false && p[i - 1] == false) {
                cnt ++;
                p[i] = true;
                p[i - 1] = true;
                cout << i << endl;
            }
        }
        cout << cnt << endl;
        return 0;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
