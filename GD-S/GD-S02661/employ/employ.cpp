#include <bits/stdc++.h>

#define fst first
#define snd second

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

const long long MOD1 = 998244353;
const long long MOD2 = 1000000007;
const long long MOD3 = 1000000009;

using ll = long long;
using ld = long double;
using namespace std;
const int N = 505, MOD = MOD1;
ll n, m, ans;
ll a[N], c[N], fac[N], res[N];
bool vis[N];
string s;
void ex_dfs(int cur, int cnt1, int cnt2) {
    if (cnt2 >= m) { ans = (ans + fac[n - cur + 1]) % MOD; return ; }
    if (cur > n) return ;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            res[cur] = i, vis[i] = 1;
            int c1 = cnt1, c2 = cnt2;
            if (a[cur]) {
                if (c1 >= c[res[cur]]) c1++;
                else c2++;
            }
            else c1++;
            ex_dfs(cur + 1, c1, c2);
            res[cur] = 0, vis[i] = 0;
        }
    }
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) a[i + 1] = s[i] - '0';
    for (int i = 1; i <= n; i++) cin >> c[i];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    if (m == n) {
        for (int i = 1; i <= n; i++) { if (!a[i] or !c[i]) return cout << 0, 0; }
        return cout << fac[n], 0;
    }
    ex_dfs(1, 0, 0); 
    cout << ans; 
    return 0;
}
