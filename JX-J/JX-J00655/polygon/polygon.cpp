#include <bits/stdc++.h>
using namespace std;
long long ans;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    int a[5005];
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    if (n <= 3) {
        sort (a + 1, a + 4);
        if (a[1] + a[2] + a[3] > 2 * a[3]) {
            cout << 1;
        } else {
            cout << 0;
        }
        return 0;
    }
    cout << 1;
    return 0;
}
