#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010][5], res, max1, max2, max3;
void dfs(ll x, ll n, ll lim1, ll lim2, ll lim3, ll ans){
    if(x > n){
        res = max(res, ans);
        return ;
    }
    if(lim1 < n / 2) dfs(x + 1, n, lim1 + 1, lim2, lim3, ans + a[x][0]);
    if(lim2 < n / 2) dfs(x + 1, n, lim1, lim2 + 1, lim3, ans + a[x][1]);
    if(lim3 < n / 2) dfs(x + 1, n, lim1, lim2, lim3 + 1, ans + a[x][2]);
}
bool cmp(ll x, ll y){
    return x > y;
}
ll findmax(ll n){
    ll b[100010];
    for(ll i = 1; i <= n; i++) b[i] = a[i][0];
    sort(b + 1, b + n + 1, cmp);
    ll ans = 0;
    for(ll i = 1; i <= n / 2; i++) ans += b[i];
    return ans;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ll t;
    cin >> t;
    while(t--){
        res = max1 = max2 = max3 = 0;
        ll n;
        bool flag = 0;
        cin >> n;
        for(ll i = 1; i <= n; i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if(a[i][1] == a[i][2] && a[i][1] == 0) continue;
            else flag = 1;
        }
        if(!flag){
            cout << findmax(n) << endl;
            continue;
        }
        if(n > 10){
            ll ans = 0;
            for(ll i = 1; i <= n; i++){
                ans += max(a[i][0], max(a[i][1], a[i][2]));
            }
            cout << ans << endl;
            continue;
        }
        dfs(1, n, 0, 0, 0, 0);
        cout << res << endl;
    }
    return 0;
}
