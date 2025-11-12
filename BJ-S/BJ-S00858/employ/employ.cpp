#include <bits/stdc++.h>
using namespace std;
//#define int long long

const int mod = 998244353;
const int N = 505;
int n, m, c[N], p[N], a[N];
string s;

void solve1 () {
    int ans = 0;
    do {
        //for (int i = 1; i <= n; ++i)
            //printf ("%d ", p[i]);
        //printf ("\n");
        int now = 0;
        for (int i = 1; i <= n; ++i) {
            //printf ("%d %d %d\n", p[i], c[p[i]], now);
            if (now >= c[p[i]]) ++ now;
            else if (a[i] == 0) ++ now;
        }
        if (n - now >= m) ++ ans;
        if (ans >= mod) ans -= mod;
        //printf ("\n");
    } while (next_permutation(p + 1, p + n + 1));
    printf ("%d\n", ans);
}

void solve2 () {
    long long ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = ans * i % mod;
    printf ("%lld\n", ans);
    return ;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i)
        a[i + 1] = (s[i] == '1');
    for (int i = 1; i <= n; ++i)
        cin >> c[i], p[i] = i;
    if (n <= 10) solve1();
    else solve2();
    return 0;
}
