#include <bits/stdc++.h>
using namespace std;
const int N = 510, mod = 998244353;
int n, m;
char s[N];
int c[N];
int p[N];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++) p[i] = i;
    int ans = 0;
    do {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt >= c[p[i]]) {
                cnt++;
                continue;
            }
            if (s[i] == '0') cnt++;
        }
        if (n - cnt >= m) {
            ans++;
            if (ans >= mod) ans -= mod;
        }
    } while (next_permutation(p + 1, p + n + 1));
    printf("%d\n", ans);
    return 0;
}
