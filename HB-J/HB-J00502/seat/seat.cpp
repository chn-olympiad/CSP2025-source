#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, a[10005], x, y;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n * m; i ++) cin >> a[i];
    ll t = a[1];
    sort(a + 1, a + n * m + 1, greater<ll>());
    for (int i = 1; i <= n * m; i ++) {
        if (a[i] == t) {
            if ((i / m) % 2 == 0) {
                if (i % m == 0) x = m, y = i / m;
                else x = i % m, y = i / m + 1;
            } else {
                if (i % m == 0) x = 1, y = i / m;
                else x = m - i % m + 1, y = i / m + 1;
            }
        }
    }
    cout << x << ' ' << y;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ll T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    return 0;
}
