#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD(998244353), MAXN(5e3 + 5);
ll a[MAXN];

bool check(ll l, ll r){
    ll sum(0), __max;
    for(int i = l; i <= r; i++){
        sum += a[i];
        __max = max(__max, a[i]);
    }
    __max *= 2;
    return sum >= __max;
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    if(n == 1 || n == 2){
        cout << 0;
        return 0;
    }
    if(n == 3){
        ll x, y, z;
        cin >> x >> y >> z;
        int _max = max({x, y, z});
        if(x + y + z > 2 * _max){
            cout << 1;
            return 0;
        }else{
            cout << 0;
            return 0;
        }
    }
    unsigned long long ans(0);
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(check(i, j)) ans++;
        }
    }
    cout << ans % MOD;
    return 0;
}
