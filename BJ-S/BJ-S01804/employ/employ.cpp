#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505;
const int mod = 998244353;
string s;
ll c[N], not_run, ans_ans, n, m, run, alive, fac[N], mx;
bool vis[N];
void dfs(int k){
    if(alive == m){
        ans_ans += fac[n - k];
        if(ans_ans > mod) ans_ans -= mod;
        return;
    }
    if(alive + n - k < m) return;
    if(mx < run) return;
    int now_run = run, now_alive = alive;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            if(run >= c[i] || s[k] == '0') run++;
            else alive++;
            dfs(k + 1);
            vis[i] = 0;
            alive = now_alive;
            run = now_run;
        }
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    fac[0] = 1;
    for(ll i = 1; i <= 20; i++) fac[i] = fac[i - 1] * i, fac[i] %= mod;
    for(int i = 1; i <= n; i++) cin >> c[i], not_run += (bool)c[i], mx = max(mx, c[i]);
    bool op = 0;
    for(int i = 1; i < s.size(); i++) if(s[i] == '0') op = 1;
    if(m == n){
        ll ans = 1;
        if(!op && not_run == n){
            for(ll i = 1; i <= n; i++) ans *= i, ans %= mod;
            cout << ans;
        }else cout << 0;
        return 0;
    }
    dfs(0);
    cout << ans_ans;
    return 0;
}
