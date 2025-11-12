#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN(5e5 + 5);
ll y[MAXN];

ll f(ll l, ll r){
    if(l == r) return y[l];
    ll res(y[l]);
    for(int i = l + 1; i <= r; i++){
        res ^= y[i];
    }
    return res;
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    if(n == 1){
        ll x;
        cin >> x;
        if(x == k){
            cout << 1;
            return 0;
        }else{
            cout << 0;
            return 0;
        }
    }
    if(n == 2){
        ll a, b, m(0);
        cin >> a >> b;
        if(a == k || b == k) m++;
        if(a ^ b == k) m++;
        cout << m;
        return 0;
    }
    bool flag = true;
    for(int i = 1; i <= n; i++){
        cin >> y[i];
        if(y[i] != 1) flag = false;
    }
    if(flag){
        if(k == 1){
            unsigned long long ff(0);
            for(int i = 1; i <= n; i++) ff += i;
            cout << ff;
            return 0;
        }else{
            cout << 0;
            return 0;
        }
    }
    ll ans(0);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(f(i, j) == k) ans++;
        }
    }
    cout << ans;
    return 0;
}
