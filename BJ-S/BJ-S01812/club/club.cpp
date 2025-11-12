#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MAXN = 2e2 + 5;
ll t, n, a[MAXN][5], dp[MAXN][5][MAXN][5], x[25], cnt[5], ans;
void dfs(ll step){
    if(step > n){
        ll res = 0;
        for(ll i = 1; i <= 3; i++) cnt[i] = 0;
        for(ll i = 1; i <= n; i++) if(x[i]) cnt[x[i]]++;
        for(ll i = 1; i <= 3; i++) if(cnt[i] > n / 2) return;
        for(ll i = 1; i <= n; i++) res += a[i][x[i]];
        ans = max(ans, res);
        return;
    }
    for(ll i = 1; i <= 3; i++){
        x[step] = i;
        dfs(step + 1);
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        cin >> n;
        for(ll i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
        ll f = 1;
        for(ll i = 1; i <= n; i++) if(!(!a[i][2] && !a[i][3])) f = 0;
        if(f == 1){
            vector <ll> tmp;
            for(ll i = 1; i <= n; i++) tmp.push_back(a[i][1]);
            sort(tmp.begin(), tmp.end());
            ans = 0;
            for(ll i = n; i >= n / 2 + 1; i--) ans += tmp[i];
            cout << ans << endl;
            continue;
        }
        if(n <= 10){
            for(ll i = 1; i <= n; i++) x[i] = 0;
            ans = 0;
            dfs(1);
            cout << ans << endl;
            continue;
        }
        for(ll i = 1; i <= n; i++){
            for(ll j = 0; j <= min(n / 2, i); j++){
                for(ll o = 1; o <= 3; o++){
                    ll x = 0, y = 0;
                    if(o == 1){
                        for(ll k = 0; k <= n / 2; k++) x = max(x, dp[i - 1][2][k][1]);
                        for(ll k = 0; k <= n / 2; k++) x = max(x, dp[i - 1][3][k][1]);
                        for(ll k = 1; k <= n / 2; k++) x = max(x, dp[i - 1][2][k][0]);
                        for(ll k = 1; k <= n / 2; k++) x = max(x, dp[i - 1][3][k][0]);
                        if(j != 0) x = max(x, dp[i - 1][1][j - 1][1]);
                        if(j >= 2) x = max(x, dp[i - 1][1][j - 1][0]);
                        if(j != 0) dp[i][1][j][0] = max(dp[i][1][j][0], x + a[i][o]);
                        y = max(y, dp[i - 1][1][j][1]);
                        if(j != 0) y = max(y, dp[i - 1][1][j][0]);
                        for(ll k = 0; k <= n / 2; k++) y = max({y, dp[i - 1][2][k][1], dp[i - 1][3][k][1]});
                        for(ll k = 1; k <= n / 2; k++) y = max({y, dp[i - 1][2][k][0], dp[i - 1][3][k][0]});
                        dp[i][1][j][1] = max(dp[i][1][j][1], y);
                        //cout << i << " " << 1 << " " << j << " " << 0 << " " << dp[i][1][j][0] << endl;
                        //cout << i << " " << 1 << " " << j << " " << 1 << " " << dp[i][1][j][1] << endl;
                    }
                    else if(o == 2){
                        for(ll k = 0; k <= n / 2; k++) x = max(x, dp[i - 1][1][k][1]);
                        for(ll k = 0; k <= n / 2; k++) x = max(x, dp[i - 1][3][k][1]);
                        for(ll k = 1; k <= n / 2; k++) x = max(x, dp[i - 1][1][k][0]);
                        for(ll k = 1; k <= n / 2; k++) x = max(x, dp[i - 1][3][k][0]);
                        if(j != 0) x = max(x, dp[i - 1][2][j - 1][1]);
                        if(j >= 2) x = max(x, dp[i - 1][2][j - 1][0]);
                        if(j != 0) dp[i][2][j][0] = max(dp[i][2][j][0], x + a[i][o]);
                        y = max(y, dp[i - 1][2][j][1]);
                        if(j != 0) y = max(y, dp[i - 1][2][j][0]);
                        for(ll k = 0; k <= n / 2; k++) y = max({y, dp[i - 1][1][k][1], dp[i - 1][3][k][1]});
                        for(ll k = 1; k <= n / 2; k++) y = max({y, dp[i - 1][1][k][0], dp[i - 1][3][k][0]});
                        dp[i][2][j][1] = max(dp[i][2][j][1], y);
                        //cout << i << " " << 2 << " " << j << " " << 0 << " " << dp[i][2][j][0] << endl;
                        //cout << i << " " << 2 << " " << j << " " << 1 << " " << dp[i][2][j][1] << endl;
                    }
                    else if(o == 3){
                        for(ll k = 0; k <= n / 2; k++) x = max(x, dp[i - 1][1][k][1]);
                        for(ll k = 0; k <= n / 2; k++) x = max(x, dp[i - 1][2][k][1]);
                        for(ll k = 1; k <= n / 2; k++) x = max(x, dp[i - 1][1][k][0]);
                        for(ll k = 1; k <= n / 2; k++) x = max(x, dp[i - 1][2][k][0]);
                        if(j != 0) x = max(x, dp[i - 1][3][j - 1][1]);
                        if(j >= 2) x = max(x, dp[i - 1][3][j - 1][0]);
                        if(j != 0) dp[i][3][j][0] = max(dp[i][3][j][0], x + a[i][o]);
                        y = max(y, dp[i - 1][3][j][1]);
                        if(j != 0) y = max(y, dp[i - 1][3][j][0]);
                        for(ll k = 0; k <= n / 2; k++) y = max({y, dp[i - 1][1][k][1], dp[i - 1][2][k][1]});
                        for(ll k = 1; k <= n / 2; k++) y = max({y, dp[i - 1][1][k][0], dp[i - 1][2][k][0]});
                        dp[i][3][j][1] = max(dp[i][3][j][1], y);
                        //cout << i << " " << 3 << " " << j << " " << 0 << " " << dp[i][3][j][0] << endl;
                        //cout << i << " " << 3 << " " << j << " " << 1 << " " << dp[i][3][j][1] << endl;
                    }
                }
            }
        }
        ans = 0;
        for(ll i = 0; i <= n / 2; i++) ans = max({ans, dp[n][1][i][1], dp[n][2][i][1], dp[n][3][i][1]});
        for(ll i = 1; i <= n / 2; i++) ans = max({ans, dp[n][1][i][0], dp[n][2][i][0], dp[n][3][i][0]});
        cout << ans << endl;
    }
    return 0;
}