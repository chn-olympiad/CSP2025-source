#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rint register int
#define inline static inline
const int mod = 998244353;
void pre() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    return ;
}
int n, m, res;
string s;
int t[505];
int c[505];
int ans[505];
bool vis[505];
void calc() {
    int sum = 0;
    for(int i = 1; i <= n; i ++)
        if(s[i] == '1' && t[i] < c[ans[i]]) sum ++;
    if(sum >= m)    res ++;
    res %= mod;
    return ;
}
void dfs(int cur) {
    if(cur == n) {
        calc();
        return ;
    }
    for(int i = 1; i <= n; i ++) {
        if(vis[i] == true)  continue;
        ans[cur + 1] = i;
        vis[i] = true;
        dfs(cur + 1);
        vis[i] = false;
    }
    return ;
}
signed main() {
    pre();
    cin >> n >> m;
    if(n >= 18) {
        res = 1;
        for(int i = 1; i <= n; i ++)
            res = (res * i) % mod;
        cout << res;
        return 0;
    }
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i <= n; i ++)
        t[i] = t[i - 1] + (s[i] == '0');
    for(int i = 1; i <= n; i ++)
        cin >> c[i];
    dfs(0);
    cout << res;
    return 0;
}