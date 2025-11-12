#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r[2000010], u[2000010], v[2000010], w[2000010], p[2000010];
ll find(ll x){
    return (x == p[x]) ? x : (p[x] = find(p[x]));
}
bool cmp(ll x, ll y){
    return w[x] < w[y];
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ll n, m, k, c, a, ans = 0;
    bool flaga = 0, flagc = 0;
    cin >> n >> m >> k;
    for(ll i = 1; i <= m; i++) cin >> u[i] >> v[i] >> w[i];
    for(ll i = 1; i <= k; i++){
        cin >> c;
        if(c) flagc = 1;
        for(ll j = 1; j <= n; j++){
            cin >> a;
            if(a) flaga = 1;
            u[++m] = j;
            v[m] = m + i;
            w[m] = c + a;
        }
    }
    if(!flaga && !flagc){
        cout << "0" << endl;
        return 0;
    }
    for(ll i = 1; i <= m; i++) p[i] = i;
    for(ll i = 1; i <= m; i++) r[i] = i;
    sort(r + 1, r + m + 1, cmp);
    for(ll i = 1; i <= m; i++){
        ll x = find(u[r[i]]), y = find(v[r[i]]);
        if(x != y){
            ans += w[r[i]];
            p[y] = x;
        }
    }
    cout << ans << endl;
    return 0;
}
