#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
#define vll vector<int>
#define all(x) (x).begin(), (x).end()
#define fpb push_back

const int N = 20, MOD = 998244353;
int n, m, c[N], ans, perm[N];
string s;
void solve() {
    // Test 1-2 (8 marks)
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        perm[i] = i;
    }
    do {
        // cout << "#\n";
        // for (int i = 1; i <= n; i++) cout << perm[i] << ' ';
        // cout << '\n';
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            // cout << cur << ' ' << c[perm[i]] << '\n';
            if (cur >= c[perm[i]] or s[i - 1] == '0') {
                cur++;
            }
        }
        if (n - cur >= m) {
            ans++;
            ans %= MOD;
        }
        // cout << n - cur << '\n';
    }while (next_permutation(perm + 1, perm + n + 1));
    cout << ans << '\n';
}


signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); int t1 = 1;
    // cin >> t1; // remove if 1 case
    while (t1--) solve();
}