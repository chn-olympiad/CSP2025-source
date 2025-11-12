# include <bits/stdc++.h>
using namespace std;
# define ll long long
const int mod = 998244353;
ll n, m, c[505];
ll ans;
string s;
ll vs[505];
void dfs(ll idx, ll t){
    if (idx == n + 1){
        if (t <= n - m) ans = (ans + 1) % mod;
        return ;
    }
    for (ll i = 1; i <= n; i ++){
        if (vs[i]) continue;
        vs[i] = 1;
        if (t >= c[i] || s[idx - 1] == '0') dfs(idx + 1, t + 1);
        else dfs(idx + 1, t);
        vs[i] = 0;
    }
    return ;
}

bool checkA(){
    for (ll i = 0; i < n; i ++) if (s[i] == '0') return 0;
    return 1;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (ll i = 1; i <= n; i ++) cin >> c[i];
    if (m == 1){
        ll k = -1;
        ans = 0;
        for (ll i = 0; i < n; i ++) if (s[i] == '1'){
            k = i;
            break;
        }
        if (k != -1){
            ans = 1;
            for (ll i = 2; i < n; i ++) ans = (ans * i) % mod;
            ll cnt = 0;
            for (ll i = 1; i <= n; i ++) if (c[i] > k) cnt ++;
            ans = (ans * cnt) % mod;
            cout << cnt << endl;
        }
        cout << ans << endl;
        return 0;
    }
    if (m == n){
        for (ll i = 0; i < n; i ++) if (s[i] == '0'){
            cout << 0 << endl;
            return 0;
        }
        for (ll i = 0; i <= n; i ++) if (c[i] == 0){
            cout << 0 << endl;
            return 0;
        }
        ans = 1;
        for (ll i = 2; i <= n; i ++) ans = (ans * i) % mod;
        cout << ans << endl;
        return 0;
    }
    if (checkA()){
        ll cnt = 0;
        for (ll i = 1; i <= n; i ++) if (c[i] == 0) cnt ++;
        if (cnt > n - m) cout << 0 << " " << endl;
        else{
            ans = 1;
            for (ll i = 2; i <= n; i ++) ans = (ans * i) % mod;
            cout << ans << endl;
        }
        return 0;
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
