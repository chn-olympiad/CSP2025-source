// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// const int N = 505;
// const int P = 998244353;
// char a[N]; 
// int s[N], f[N][N][N], fac[N], C[N][N]; 
// signed  main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     int n, m; cin >> n >> m; 
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     for (int i = 1, x; i <= n; i++) cin >> x, s[x]++;
//     for (int i = 1; i <= n;i++) s[i] += s[i - 1];
//     f[0][0][0] = 1; int cnt = 0;
//     for (int i = 1; i <= n; i++) {
//         cnt += a[i] == '0';
//         for (int j = 0; j <= i; j++) 
//             for (int k = 0; k <= j; k++) {
//                 f[i][j][k] = f[i - 1][j][k];
//                 if (a[i] == '1') {
//                     f[i][j][k] = (f[i - 1][j - 1][k] + f[i][j][k]) % P;
//                     if (s[cnt + j - 1] >= k)
//                         f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k - 1] * (s[j + cnt - 1] - k + 1)) % P;
//                 } printf("f[%lld][%lld][%lld]=%lld\n", i, j, k, f[i][j][k]);
//             }
//     }
//     int ans = 0; fac[0] = 1;
//     for (int i = 1; i <= n; i++)
//         fac[i] = fac[i - 1] * i % P;
//     // for (int i = 0; i <= n; i++)
//     //     for (int j = 0; j <= i; j++)
//     //         C[i][j] = (!j ? 1 : C[i - 1][j - 1] + C[i - 1][j]) % P;
//     for (int i = n - m - cnt + 1; i <= n - cnt + 1; i++) {
//         int s = 0;
//         for (int j = 0; j <= i; j++) {
//             int w = f[n][i][j] * fac[n - j] % P;
//             if (i - j & 1 ^ 1) s = (s - w + P) % P;
//             else s = (s + w) % P;
//         } ans = (ans + s) % P; cout << i << ' ' << s << '\n';
//     }
//     cout << (fac[n] - ans + P) % P  << '\n'; 
//     return 0; 
// }
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int P = 998244353;
char a[N]; 
int b[N], t[N]; 
signed  main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, ans = 0; cin >> n >> m; 
    for (int i = 1; i <= n; i++) cin >> a[i], t[i] = i;
    for (int i = 1; i <= n; i++) cin >> b[i];
    if (n <= 10) {
        do {
            int s = 0;
            for (int i = 1; i <= n; i++)
                if (s >= b[t[i]] || a[i] == '0') s++;
            ans += s <= n - m; 
        } while (next_permutation(t + 1, t + 1 + n));
    } else  {
        bool f = 1;
        for (int i = 1; i <= n; i++)
            f &= b[i] > 0 && a[i] == '1';
        if (!f) ans = 0; 
    }
    cout << ans << '\n';
    return 0; 
}