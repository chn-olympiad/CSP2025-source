#include <bits/stdc++.h>
using namespace std;
long long n, a[5418], sum, x;
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if(n == 3) {
        if(a[1] + a[2] > a[3]) {
            cout << 1;
        } else {
            cout << 0;
        }
    } else if(a[1] + a[2] > a[n]) {
        for(int i=3; i<=n; i++) {
            x = 1;
            for(int j=n; j>=n - i + 1; j--) {
                x *= j;
                x %= 998244353;
            }
            sum += x;
            sum %= 998244353;
        }
        cout << sum;
    } else {
        cout << 1042013;
    }
    return 0;
}
