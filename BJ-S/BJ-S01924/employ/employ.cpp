#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr ll mod = 998244353;
ll n, m;
string s;
ll c[2000];
ll p[2002];
bool vis[2002];
ll res = 0;
void dfs(ll cur) {
    if(cur == n + 1) {
        ll cnt = 0, ans = 0;
        for(int i = 1; i <= n; i++) {
            if(c[p[i]] > cnt)
                ans += s[i - 1] == '1', cnt += s[i - 1] == '0';
            else
                cnt++;
        }
        // cout << p[1] << " " << p[2] << " " << p[3] << " : " << ans << "\n";
        res += ans >= m;
        res %= mod;
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            p[cur] = i;
            dfs(cur + 1);
            vis[i] = 0;
        }
    }
    return ;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    dfs(1);
    cout << res % mod;
    return 0;
}