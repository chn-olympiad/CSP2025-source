#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , k;
ll a[500005];
ll xr[500005];
ll ans = 0;
ll cnt[1000005];
ll lst = 0;
int main() {
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> k;
    for(ll i = 1 ; i <= n ; i++){
        cin >> a[i];
        xr[i] = a[i];
        xr[i] ^= xr[i - 1];
    }
    //for(ll l = 0 , r = 1 ; r <= n ; r++){
    //    for(ll i = l ; i < r ; i++){
    //        if((xr[i] ^ xr[r]) == k){
    //             cout << i << " " << r << endl;
    //           cout << xr[i] << " " << xr[r] << endl;
    //           cout << (xr[i] xor xr[r]) << endl;
    //            ans++;
    //            l = r;
    //            break;
    //        }
    //    }
    //}
    //cout << ans << endl;
    ans = 0;
    cnt[0] = 1;
    for(ll i = 1 ; i <= n ; i++){
        ll x = (k xor (xr[i] xor lst));
        if(cnt[x] != 0){
            ans++;
            memset(cnt , 0 , sizeof(cnt));
            cnt[0] = 1;
            //cout << lst << "xor" << xr[i] << endl;
            lst = xr[i];
            //cout << lst << endl;
            //cout << i << endl;
        }else{
            cnt[(xr[i] xor lst)]++;
       }
       //cout << i << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
