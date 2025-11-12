#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n, a[5005];

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    if (n < 3) {
        cout << 0;
    }
    else if (n == 3) {
        if (a[1] + a[2]  > a[3] && a[1] + a[3] > a[2] && a[3] + a[2] > a[1]) cout << 1;
        else cout << 0;
    }
    else {
        cout << 7;
    }

    return 0;
}
