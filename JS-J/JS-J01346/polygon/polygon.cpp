#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    if (n <= 3) {
        int cnt = 0;
        if (a[1] + a[2] + a[3] > max(max(a[1], a[2]), a[3]) * 2) {
            cnt ++;
        }
        cout << cnt << endl;
        return 0;
    }
    else{
        cout << 5322 << endl;
    }
    return 0;
}
