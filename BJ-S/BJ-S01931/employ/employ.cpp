#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define pii pair < int , int >
#define mp(i, j) make_pair(i, j)

const int N = 505;
const int mod = 998244353;
int n, m, c[N], a[N], t[N], f[2][19][1 << 19];
char s[N];

void solve1() {
    for(int i = 1; i <= n; i++) a[i] = i;
    int ans = 0;
    do {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(s[i] == '0' || cnt >= c[a[i]]) cnt ++;
        if(n - cnt >= m) ans ++;
    } while(next_permutation(a + 1, a + 1 + n));
    cout << ans <<"\n";
}

bool cmp(int x, int y) {
    return c[x] > c[y];
}

void solve2() {
    for(int i = 1; i <= n; i++) a[i] = i;
    sort(a + 1, a + 1 + n, cmp);
    int res = 1;
    for(int i = 1; i <= n; i++) {
        int x = a[i];
        int cnt = 0;
        for(int j = 1; j <= n; j++)
            if(s[j] == '0' || j > c[x]) cnt ++;
        cnt -= (i - 1);
        if(cnt <= 0) res = 0;
        else res = (ll) res * cnt % mod;
    }
    ll ans = 1;
    for(int i = 1; i <= n; i++) ans = (ll) ans * i % mod;
    ans = (ans % mod - res + mod) % mod;
    ans = (ans % mod + mod) % mod;
    cout << ans << "\n";
}

void solve3() {
    int ok = 1;
    for(int i = 1; i <= n; i++)
        if(s[i] == '0' || c[i] == 0) ok = 0;
    if(!ok) {
        cout << 0; return;
    }
    int ans = 1;
    for(int i = 1; i <= n; i++) ans = (ll) ans * i % mod;
    cout << ans << "\n";
}

void solve4() {
    int ans = 1;
    for(int i = 1; i <= n; i++) ans = (ll) ans * i % mod;
    cout << ans << "\n";
}

void solve5() {
    f[0][0][0] = 1;
    int c = 0;
    for(int i = 1; i <= n; i++) {
        c ^= 1;
        for(int j = 0; j <= i; j++) {
            for(int s = 0; s < (1 << n); s++) {
                if(__builtin_popcount(s) != i) continue;
                for(int k = 1; k <= n; k++) {
                    if(s >> k - 1 & 1) {
                        if(c[k] > j - 1) f[c][j][s] = (f[c][j][s] + f[!c][j - 1][s ^ (1 << k - 1)]) % mod;
                        if(c[k] <= j) f[c][j][s] = (f[c][j][s] + f[!c][j][s ^ (1 << k - 1)]) % mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = m; i <= n; i++) ans = (ans + f[n][i][(1 << n) - 1]) % mo;
    cout << ans << "\n";
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s + 1;
    for(int i = 1; i <= n; i++) cin >> c[i];
    if(n <= 10) solve1();
    else if(m == 1) solve2();
    else if(m == n) solve3();
    else solve4();
    return 0;
}
