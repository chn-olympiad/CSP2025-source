#include <iostream>
using namespace std;
using ll = long long;

const int N = 5e5 + 1;

ll n, k, a[N], maxx = 1, n1 = 0;

ll solve(ll l, ll r) {
    if (r == l) {
        if (a[l] == k) return 1;
        else return 0;
    }
    ll ans = 0, s = a[l];
    for (int i = l + 1; i <= r; ++i) s ^= a[i];
    if (s == k) ++ans;
    for (int i = l; i < r; ++i) {
        ll key = solve(l, i) + solve(i + 1, r);
        if (key > ans) {
            ans = key;
        }
    }
    return ans;
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > maxx) maxx = a[i];
        if (a[i] == 1) ++n1;
    }
    if (maxx < k) {
        cout << 0;
        return 0;
    }
    if (maxx == 1) {
        cout << n1;
        return 0;
    }
    cout << solve(1, n);
    return 0;
}
