#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353

int a[5005], ans;

signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i <= (1 << (n + 1)); i++) {
        //cout << i << '\n';
        int Max = 0, sum = 0, cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(i & (1 << j)) {
                Max = max(Max, a[j]);
                sum += a[j];
                cnt++;
            }
        }
        if(sum > (Max * 2) && cnt >= 3) {
            ans++;
            ans %= MOD;
            //cout << sum << " " << Max << '\n';
        }
    }
    cout << ans / 2;
    return 0;
}
