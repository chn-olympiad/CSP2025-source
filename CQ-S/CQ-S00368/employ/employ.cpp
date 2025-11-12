#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second 
#define pb push_back 
#define mk make_pair 
#define db double 
using namespace std;
const int MAXN = 1e3 + 5, INF = 1e18, MAXK = 20, mod = 998244353;

int Quick_pow(int a, int b) {
    int res = 1;
    while (b){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int n, m, sum, sum2, ans;
int s[MAXN], c[MAXN], fac[MAXN], inv[MAXN], p[MAXN], pre[MAXN], g[MAXN];
int f[MAXK][1ll << MAXK];
char S[MAXN];

int C(int a, int b) {
    if (a < b) return 0ll;
    return fac[a] * inv[b] % mod * inv[a - b] % mod;
}

void Solve1() {
    for (int i = 1; i <= n; i ++) p[i] = i;
    do {
        int x = 0, y = 0;
        for (int i = 1; i <= n; i ++){
            if (s[i] == 0) x ++;
            else {
                if (x >= c[p[i]]) x ++;
                else y ++;
            }
        }
        if (y >= m) ans ++;
    }
    while (next_permutation(p + 1, p + n + 1));
    printf("%lld\n", ans);
}

void Solve2() {
    f[0][0] = 1;
    for (int i = 1; i < (1ll << n); i ++){
        int peo = 0;
        for (int j = 1; j <= n; j ++)
            if ((i & (1ll << (j - 1)))) peo ++;
        for (int j = 1; j <= n; j ++){
            if (!(i & (1ll << (j - 1)))) continue;
            int I = i ^ (1ll << (j - 1));
            for (int k = 0; k <= n; k ++){
                if (s[peo] == 0){
                    if (k > 0) f[k][i] += f[k - 1][I], f[k][i] %= mod;
                }
                else {
                    if (k - 1 >= c[j]) f[k][i] += f[k - 1][I], f[k][i] %= mod;
                    if (k < c[j]){
                        // printf("upd %lld %lld %lld\n", i, I, k);
                        f[k][i] += f[k][I], f[k][i] %= mod;
                    }
                }
            }
        }
        // for (int j = 0; j <= n; j ++) printf("%lld %lld %lld\n", i, j, f[j][i]);
    }
    for (int i = 0; i <= n - m; i ++) ans += f[i][(1ll << n) - 1], ans %= mod;
    printf("%lld\n", ans);
}

void Solve3() {
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i ++) pre[c[i]] ++;
    for (int i = 1; i <= n; i ++) pre[i] += pre[i - 1];
    int lst = 0, num = 1ll, Sum = 0;
    for (int i = 1; i <= n; i ++){
        if (s[i] == 1){
            ans += C(pre[n] - pre[i - 1], 1) * num * fac[n - (Sum + 1)], ans %= mod;
            num *= C(pre[i - 1] - Sum, 1), num %= mod;
            Sum ++;
        }
    }
    ans = fac[n] - ans + mod;
    ans %= mod;
    printf("%lld\n", ans);
}

void Solve() {
    sum = sum2 = 0;
    cin >> n >> m;
    fac[0] = inv[0] = 1ll;
    for (int i = 1; i <= n; i ++) fac[i] = fac[i - 1] * i % mod, inv[i] = Quick_pow(fac[i], mod - 2);
    for (int i = 1; i <= n; i ++){
        cin >> S[i], s[i] = (S[i] == '1');
        sum += s[i];
    }
    for (int i = 1; i <= n; i ++) cin >> c[i], sum2 += (c[i] == 0);
    if (m == n){
        printf("%lld\n", (sum - sum2 == n) ? fac[n] : 0ll);
        return;
    }
    if (n <= 10) return Solve1(), void();
    if (n <= 18) return Solve2(), void();
    if (m == 1) return Solve3(), void();
}

signed main() {
    // if (!system("fc employ.out employ1.ans")) puts("Yes");
    // else puts("No");
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while (T --) Solve();
    return 0;
}