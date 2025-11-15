#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll club[n][3], mark[n] = {0}, maxn[n] = {0}, full[3] = {0};
        for (ll i = 0; i < n; i++){
            for (ll j = 0; j < 3; j++){
                cin >> club[i][j];
            }
            if (club[i][0] > club[i][1]){
                maxn[i] = club[i][0];
                mark[i] = 0;
                if (club[i][0] < club[i][2]){
                    maxn[i] = club[i][2];
                    mark[i] = 2;
                }
            } else{
                maxn[i] = club[i][1];
                mark[i] = 1;
                if (club[i][1] < club[i][2]){
                    maxn[i] = club[i][2];
                    mark[i] = 2;
                }
            }
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++){
            ll maxi = 0;
            ll marki = 0;
            for (ll j = 0; j < n; j++){
                if (maxn[i] >= maxi){
                    maxi = maxn[i];
                    marki = i;
                }
            }
            maxn[marki] = -1;
            if (++full[mark[marki]] <= (n/2)){
                ans += maxi;
            } else {
                sort(club[marki], club[marki]+3);
                ans += club[marki][1];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}