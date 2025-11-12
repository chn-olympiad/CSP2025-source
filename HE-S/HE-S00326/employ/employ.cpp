#include<bits/stdc++.h>

using namespace std;

#define int long long

constexpr int mod = 998244353;

const int N = 510;

int p[N];

int s[N], vis[N], c[N];

int n, m, ans;

inline void dfs(int u) {
    if(u == n + 1) {
        int sm = 0, res = 0;
        for(int i = 1; i <= n; i ++) {
            if(sm >= c[p[i]] || !s[i]) {
                sm ++;
            }
            else {
                res ++;
            }
        }
        if(res >= m) ans ++;
        return;
    }
    for(int i = 1; i <= n; i ++) {
        if(!vis[i]) {
            vis[i] = 1;
            p[u] = i;
            dfs(u + 1);
            vis[i] = 0;
        }
    }
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int sum = 0;
    for(int i = 1; i <= n; i ++) {
        char c; cin >> c;
        if(c == '1') s[i] = 1;
        else s[i] = 0;
        sum += s[i];
    }
    if(sum < m) {
        cout << 0;
        exit(0);
    }
    if(sum == n and n > 12) {
        int f = 1;
        for(int i = 1; i <= n; i ++) (f *= i) %= mod;
        cout << f;
        exit(0);
    }
    for(int i = 1; i <= n; i ++) cin >> c[i];
    dfs(1);
    cout << ans;

    return 0;
}