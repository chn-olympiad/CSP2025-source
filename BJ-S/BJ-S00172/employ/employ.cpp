#include <bits/stdc++.h>

using namespace std;

const int N = 510, mod = 998244353;
int n, m, ans, c[N], p[N];
char s[N];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> s + 1;
    // assert(strlen(s + 1) == n);
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort(c + 1, c + 1 + n);
    bool A = true;
    for (int i = 1; i <= n; i++)
        if (s[i] != '1')
            A = false;
    // if (A) {
    //     int c0 = 0;
    //     for (int i = 1; i <= n; i++) c0 += c[i] == 0;
    //     if (n - c0 >= m) {
    //         ans = 1;
    //         for (int i = 1; i <= n; i++) ans = 1ll * ans * i % mod;
    //         cout << ans << '\n';
    //     }
    //     else cout << "0\n";
    //     return 0;
    // }
    if (n == m) {
        if (!A) {
            cout << "0\n";
            return 0;
        }
        int c0 = 0;
        for (int i = 1; i <= n; i++) c0 += c[i] == 0;
        if (c0) {
            cout << "0\n";
            return 0;
        }
        ans = 1;
        for (int i = 1; i <= n; i++) ans = 1ll * ans * i % mod;
        cout << ans << '\n';
        return 0;
    }
    iota(p + 1, p + 1 + n, 1);
    do {
        // for (int i = 1; i <= n; i++) printf("%d ", p[i]);
        // cout << '\n';
        int c0 = 0, c1 = 0;
        for (int i = 1; i <= n && c1 < m; i++) {
            if (s[i] == '0') c0++;
            else if (c[p[i]] <= c0) c0++;
            else c1++;
            // printf("i = %d p = %d c0 = %d c1 = %d\n", i, p[i], c0, c1);
        }
        // printf("c1 = %d\n", c1);
        ans += c1 >= m;
    } while(next_permutation(p + 1, p + 1 + n));
    ans %= mod;
    cout << ans << '\n';
    return 0;
}