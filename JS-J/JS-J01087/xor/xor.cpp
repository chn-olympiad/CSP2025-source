#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, a[N], k; bool A = true;
signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false); // xor
    cin.tie(0); cout.tie(0); // same: 0, different: 1
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (k == 0 && a[i] != 1) A = false;
    }
    if (A) {
        cout << n / 2 * 2;
        return 0;
    }

    return 0;
}
