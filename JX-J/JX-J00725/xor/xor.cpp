#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int main () {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == k) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
