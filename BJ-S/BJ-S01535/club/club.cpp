#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
ll a[N][3];
ll cnt;
bool cmp(ll x, ll y){
    ll maxx = -1, maxy = -1;
    for (ll i = 0;i <= 2;i++){
        if (i == cnt) continue;
        maxx = max(maxx, a[x][i]);
        maxy = max(maxy, a[y][i]);
    }
    return a[x][cnt] - maxx < a[y][cnt] - maxy;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        vector<ll> v[3];
        for (ll i = 1;i <= n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            ll maxn = 0, idx = 0;
            for (ll j = 0;j <= 2;j++){
                if (a[i][j] > maxn){
                    maxn = a[i][j];
                    idx = j;
                }
            }
            v[idx].push_back(i);
        }
        for (ll i = 0;i <= 2;i++){
            if (v[i].size() > n / 2){
                cnt = i;
                sort(v[i].begin(), v[i].end(), cmp);
                for (ll j = 0;j < v[i].size() - n / 2;j++){
                    //cout << j << " ";
                    //continue;
                    ll maxn = -1, idx = 0;
                    for (ll k = 0;k <= 2;k++){
                        if (k == i) continue;
                        if (a[v[i][j]][k] > maxn){
                            maxn = a[v[i][j]][k];
                            idx = k;
                        }
                    }
                    v[idx].push_back(v[i][j]);
                }
                //return 0;
                break;
            }
        }
        ll ans = 0;
        for (ll i = 0;i <= 2;i++){
            reverse(v[i].begin(), v[i].end());
            for (ll j = 0;j < min(n / 2, (ll)(v[i].size()));j++){
                ans += a[v[i][j]][i];
            }
        }
        cout << ans << "\n";
    }
	return 0;
}
