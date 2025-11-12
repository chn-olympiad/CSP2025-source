#include <iostream>
using namespace std;

typedef long long ll;

const ll N = 10005;
const ll MOD = 998244353;
int flag = 1;

ll n, ans;
ll a[5005];


int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) flag = 0;
    }
    if (flag == 0) {
        ll U = 1 << (n+1) - 1;
        for (ll i = 1; i <= U; i++) {
            ll sumn = 0, maxn = 0, m = 0;
            for (ll j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    m++;
                    sumn += a[j+1];
                    maxn = max(maxn, a[j+1]);
                }
            }
            if (sumn > maxn * 2 && m >= 3) {
                ans = (ans + 1) % MOD;
            }
        }
        cout << ans;
    } else {
        ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans * 2) % MOD;
        }
        ans = (ans - 1) % MOD;
        ans = (ans - n*n%MOD) % MOD;
        cout << ans;
    }
    return 0;
}
