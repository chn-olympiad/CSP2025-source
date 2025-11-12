#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500050], ans, tmp;

signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp ^= a[i];
        if(tmp == k) {
            ans++;
            tmp = 0;
        }
    }
    cout << ans;

    return 0;
}
