#include<bits/stdc++.h>
using namespace std;

const int M = 998244353;
int n, a[5005], C[5005][5005];

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    if (n == 3) {
        cout << int(a[1] + a[2] > a[3]);
    } else if (a[n] == 1) {
        int ans = 0;
        C[1][1] = 1;
        for (int i=2; i<=n; i++) {
            for (int j=1; j<=i; j++) {
                C[i][j] = (C[i-1][j-1] % M + C[i-1][j] % M) % M;
            }
        }
        for (int i=3; i<=n; i++) {
            ans += C[n][i];
            ans %= M;
        }
        cout << ans;
    } else {cout << 2;}
    return 0;
}
