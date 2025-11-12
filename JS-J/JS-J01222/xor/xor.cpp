#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5E5 + 5;
ll pre[MAXN];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    map <ll, ll> mp;
    mp[0] = 0;

    ll n, k; cin >> n >> k;

    for(int i = 1; i <= n; i++ ){
        cin >> pre[i];
        pre[i] ^= pre[i - 1];
    }

    //for(int i = 1; i <= n; i++ ) cout << pre[i] << ' ';
    //cout << '\n';

    ll id(0);
    ll ans(0);
    for(ll i = 1; i <= n; i++ ){

        if((pre[i] ^ pre[i - 1]) == k){
            id = i;
            ans++;
            //cout << i << "bingo!" << '\n';
            mp[pre[i]] = i;
            continue;
        }

        ll x = k ^ pre[i];
        if(mp.count(x) && mp[x] >= id){
            id = i;
            ans++;
            //cout << i << '\n';
        }

        mp[pre[i]] = i;

    }

    cout << ans;

    return 0;

}
