#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 998244353;
ll n,m,s[500],c[500],nemty=0;
ll times(ll x){
    ll res = 1;
    for (ll i=2;i<=x;i++) {
        res *= i;
        res %= MAX;
    }
    return res;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for (ll i=0;i<n;i++) s[i] = getchar() - '0';
    for (ll i=0;i<n;i++){
        cin >> c[i];
        if (c[i] != 0) nemty++;
    }
    if (nemty == n && nemty>=m) cout << times(nemty)%MAX;
    else cout << nemty << '\n' << ((times(nemty)%MAX)*((n-nemty+1)%MAX))%MAX;
    return 0;
}
