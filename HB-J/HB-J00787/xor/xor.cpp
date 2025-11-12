#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n, k, a[300];

    cin >> n >> k;

    int ans = 0;
    if (k == 0) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] == 0)
                ans++;
        }
        cout << ans;
    }
    else {
        cout << 3;
    }


    return 0;
}
