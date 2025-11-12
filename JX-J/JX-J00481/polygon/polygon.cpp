#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define endl "\n"
const ll mod = 998244353;
ll n , ans;
ll a[100010];
void dfs (ll sum , ll step , ll maxn , ll num) {
    if (step >= n) {
        if (num < 3) return ;
        if (sum > maxn * 2) ans += 1;
        return ;
    }
    dfs (sum , step + 1 , maxn , num);
    dfs (sum + a[step + 1] , step + 1 , max (maxn , a[step + 1]) , num + 1);
}
int main(){
    IOS
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i ++ ) cin >> a[i];
    dfs (0 , 0 , 0 , 0);
    cout << ans % mod;
    return 0;
}
