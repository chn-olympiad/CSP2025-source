#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n;
ll a[5005];
ll ans = 0;
int main() {
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for(ll i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    for(ll i = 1 ; i <= (1 << n) ; i++){
        ll mx = 0 , sum = 0 , cnt = 0;
        for(ll j = 1 ; j <= n ; j++){
            if((i >> (j - 1)) & 1){
                cnt++;
                sum += a[j];
                mx = max(mx , a[j]);
            }
        }
        if(cnt < 3){
            continue;
        }
        if(sum > 2 * mx){
            ans++;
            ans = (ans) % mod;
        }
    }
    cout << ans;
    return 0;
}
