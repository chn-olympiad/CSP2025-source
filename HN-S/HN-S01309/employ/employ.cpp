#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 505, mod = 998244353;
int n, m, d[N], p[N], sum[N], last[N], tot;
ll fac[N], ifac[N];
char s[N];
ll qp(ll x, int n) {
    ll ret = 1;
    while (n) {
        if (n & 1)ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}
ll C(int a, int b) {
    if (a < b || b < 0)return 0;
    return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}
void solveBF() {
    iota(p, p + n, 0);
    int ans = 0;
    do {
        int sum = 0, ic = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '0')sum++;
            else {
                if (sum >= d[p[i]])sum++;
                else ic++;
            }
        if (ic >= m)ans++;
    } while (next_permutation(p, p + n));
    cout << ans << '\n';
}
//void solveDP() {
//    int up = 1 << tot;
//    dp[0]=1;
//    for (int b = 0; b < up; b++) {
//        for (int i = 0; i < n; i++)
//            for(int j=0;j<tot;j++)
//            if(~b>>j&1){
//                if()
//            }
//    }
//}
void solve() {
    cin >> n >> m >> s;
    sum[0] = s[0] == '0';
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + (s[i] == '0');
    for (int i = 0; i < n; i++)
        if (s[i] == '0')last[++tot] = i;
    while (tot < n)last[++tot] = n;
    for (int i = 0; i < n; i++)cin >> d[i];
    sort(d, d + n);
    if (n <= 10) {
        solveBF();
        return;
    }
    int s1 = count(s, s + n, '1');
    if (s1 < m) {
        cout << "0\n";
        return;
    }
//    int mc = count(d, d + n, n);
//    if (s1 <= 18) {
//        solvedp(s1);
//        return ;
//    }
    if (m == n) {
        ll ans = 1;
        for (int i = 0; i < n; i++) {
            if (i >= last[d[i]])ans = 0;
            ans = ans * (last[d[i]] - i) % mod;
        }
        cout << ans << '\n';
        return;
    }
    if (m == 1) {
        ll ans = 1;
        for (int i = n - 1; i >= 0; i--) {
            int used = n - i - 1, can = n - d[i];
            for (int j = 0; j < d[i]; j++)can += s[i] == '0';
            if (can <= used)ans = 0;
            ans = ans * (can - used) % mod;
        }
        cout << (fac[n] - ans + mod) % mod << '\n';
        return;
    }
    if (s1 == n) {
        int pos = 0, sum = 0;
        while (pos < n && d[pos] <= sum)pos++, sum++;
        cout << fac[n - pos] << '\n';
        return ;
    }
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    fac[0] = 1;
    for (int i = 1; i <= 500; i++)fac[i] = fac[i - 1] * i % mod;
    ifac[500] = qp(fac[500], mod - 2);
    for (int i = 500; i > 0; i--)ifac[i - 1] = ifac[i] * i % mod;
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
