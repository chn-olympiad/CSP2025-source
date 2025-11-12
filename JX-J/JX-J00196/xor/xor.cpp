#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAX_N = 5e5 + 5;

ll n, k;
ll a[MAX_N];
ll ans, cnt;
bool b[MAX_N], flag;
bool b1[MAX_N], b2[MAX_N];

int main () {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == k) {
            ans++;
            b[i] = 1;
        }
    }

    for (int len = 2; len <= n; len++) {
        int ans1 = 0, ans2 = 0;
        memset (b1, 0, sizeof (b1));
        memset (b2, 0, sizeof (b2));
        for (ll i = 1; i <= n - len + 1; i++) {
            ll j = i + len - 1;
            if (b[i] == 1) {
                continue;
            }
            cnt = a[i];
            flag = 1;
            for (ll l = i + 1; l <= j; l++) {
                cnt ^= a[l];
                if (b[l] == 1 || b1[l] == 1) {
                    flag = 0;
                    continue;
                }
            }
            if (cnt == k && flag) {
                ans1++;
                for (ll l = i; l <= j; l++) {
                    b1[l] = 1;
                }
            }
        }
        for (ll i = n - len + 1; i >= 1; i--) {
            ll j = i - len + 1;

            if (b[i] == 1) {
                continue;
            }
            cnt = a[i];
            flag = 1;
            for (ll l = i - 1; l >= j; l--) {
                cnt ^= a[l];
                if (b[l] == 1 || b2[l] == 1) {
                    flag = 0;
                    continue;
                }
            }
            if (cnt == k && flag) {
                ans2++;
                for (ll l = i; l >= j; l--) {
                    b2[l] = 1;
                }
            }
        }
        if (ans1 > ans2) {
            for (ll i = 1; i <= n; i++) {
                if (b1[i]) {
                    b[i] = 1;
                }
            }
        } else {
            for (ll i = 1; i <= n; i++) {
                if (b2[i]) {
                    b[i] = 1;
                }
            }
        }
        ans += max (ans1, ans2);
    }
    cout << ans << endl;
    return 0;
}
