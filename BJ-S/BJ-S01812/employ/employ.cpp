#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXN = 5e3 + 5, MOD = 998244353;
ll n, m, s[MAXN], c[MAXN], a[MAXN], ans;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        char x;
        cin >> x;
        s[i] = x - '0';
    }
    for(ll i = 1; i <= n; i++) cin >> c[i];
    for(ll i = 1; i <= n; i++) a[i] = i;
    ll f = 1;
    for(ll i = 1; i <= n; i++) if(s[i] == 0) f = 0;
    if(f == 1){
        ll cnt = 0;
        for(ll i = 1; i <= n; i++) if(c[i] != 0) cnt++;
        if(cnt >= m){
            ans = 1;
            for(ll i = 1; i <= n; i++) ans = ans * i % MOD;
            cout << ans;
        }
        else cout << 0;
        return 0;
    }
    if(n <= 10){
        ll tmp = 1;
        for(ll i = 1; i <= n; i++) tmp = tmp * i;
        for(ll i = 1; i <= tmp; i++){
            ll cnt = 0, f = 1, res = 0;
            for(ll j = 1; j <= n; j++){
                if(cnt >= c[a[j]]){
                    cnt++;
                }
                else if(s[j] == 0) cnt++;
                else res++;
            }
            //for(ll j = 1; j <= n; j++) cout << a[j] << " ";
            //cout << endl;
            next_permutation(a + 1, a + 1 + n);
            if(res >= m) ans = (ans + 1) % MOD;
        }
        cout << ans;
    }
    return 0;
}