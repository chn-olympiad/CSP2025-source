#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e6 + 10;
const int B = 10007;
const int mod = 998244853;
int n, q;
struct node {
    string s1, s2;
    int h1, h2;
} a[N];
string t1, t2;
int h[N], H;
int pw[N];
void init() {
    pw[0] = 1;
    for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * B % mod;
}
void solve() {
    cin >> t1 >> t2;
    if (t1.size() != t2.size()) return cout << "0\n", void();
    for (int i = 0; i < t1.size(); i++)
        h[i] = ((t1[i] - 'a' + 1) * pw[i] % mod + h[i - 1]) % mod;
    for (int i = 0; i < t2.size(); i++)
        H = ((t2[i] - 'a' + 1) * pw[i] % mod + H) % mod;
    int ans = 0;
    for (int x = 1; x <= n; x++) {
        int len = a[x].s1.size();
        for (int i = 0; i + len - 1 < t1.size(); i++) {
            int val;
            if (i == 0) {
                val = h[i + len - 1];
                if (val != a[x].h1) continue;
                val = (h[t1.size() - 1] - val + a[x].h2 + mod) % mod;
            } else {
                val = (h[i + len - 1] - h[i - 1] + mod) % mod;
                if (val != a[x].h1 * pw[i] % mod) continue;
                val = (h[t1.size() - 1] - h[i + len - 1] + h[i - 1] + mod + a[x].h2 * pw[i]) % mod;
            }
            if (val == H) ans++;
        }
    }
    cout << ans << '\n';
}
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    init();
    cin >> n >> q;
    for (int x = 1; x <= n; x++) {
        cin >> a[x].s1 >> a[x].s2;
        for (int i = 0; i < a[x].s1.size(); i++)
            a[x].h1 = (a[x].h1 + (a[x].s1[i] - 'a' + 1) * pw[i] % mod) % mod;
        for (int i = 0; i < a[x].s2.size(); i++)
            a[x].h2 = (a[x].h2 + (a[x].s2[i] - 'a' + 1) * pw[i] % mod) % mod;
        // cout << a[x].h1 << ' ' << a[x].h2 << '\n';
    }
    while (q--) solve();
}