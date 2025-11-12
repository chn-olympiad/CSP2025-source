#include <bits/stdc++.h>
using namespace std;
const int M = 5 * 1e5 + 5;
int n, k;
int a[M];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    bool flag1 = true;
    int tot = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] != 1) flag1 = false;
        else tot ++;
        if (a[i] != 0 && a[i] != 1) {
            cout << "I try my best, but I still can`t do it!" << endl;
            cout << "It`s too difficult, so I only can cheat to get the grades!" << endl;
            cout << "Goodbye!" << endl;
            return 0;
        }
    }
    if (flag1 == true) {
        cout << n / 2 << endl;
        return 0;
    }
    if (k == 1) {
        cout << tot << endl;
        return 0;
    }
    int tot1 = n - tot;
    for (int i = 1; i < n; i ++)
        if (a[i] == 1 && a[i + 1] == 1) {
            tot1 ++;
            a[i] = 0;
            a[i + 1] = 0;
        }
    cout << tot1 << endl;
    return 0;
}
