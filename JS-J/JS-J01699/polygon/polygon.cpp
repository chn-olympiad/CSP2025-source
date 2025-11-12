#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[5005];
ll dfs(ll tot, ll mx, ll num, ll st){
    if(st == n + 1){
        if(tot > mx * 2 && num >= 3) return 1;
        return 0;
    }
    return (dfs(tot + a[st], a[st], num + 1, st + 1)
         + dfs(tot, mx, num, st + 1)) % 998244353;
}
ll mpow(ll num){
    ll res = 1;
    for(ll i = 1; i <= num; i++){
        res *= 2;
        res %= 998244353;
    }return res;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%lld", &n);
    ll mx = INT_MAX;
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        mx = max(mx, a[i]);
    }if(mx == 1){
        ll ans = mpow(n) - (n * (n - 1) / 2) - n - 1;
        if(ans < 0) ans += 998244353;
        cout << ans;
    }else if(n <= 20){
        sort(a + 1, a + n + 1);
        printf("%lld", dfs(0, INT_MAX, 0, 1));
    }
    return 0;
}
