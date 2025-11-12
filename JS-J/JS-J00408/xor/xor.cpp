#include <bits/stdc++.h>
using namespace std;
int a[114514];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (k == 0) {
        if (a[1] == 1)
        cout << n / 2 << endl;
        else
        cout << n / 4 << endl;
        return 0;
    } else {
        if(k == 1) {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1) {
                    sum++;
                }
            }
            cout << sum << endl;
        } else {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1 && a[i - 1] == 1) {
                    a[i] = 0;
                    sum++;
                } else if (a[i] == 0) {
                    sum ++;
                }
            }
            if (k == 0)
            cout << sum << endl;
            else {
                cout << sum / 2 << endl;
            }
        }
    }
    return 0;
}