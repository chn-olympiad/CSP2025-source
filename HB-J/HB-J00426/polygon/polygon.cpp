#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5010, MOD = 998244353;
int n;
ll arr[N];

ll dfs(ll depth, ll ans, ll mx){
    if(depth > n){
        if(ans <= 2 * mx){
            return 0;
        }
        return 1;
    }
    return dfs(depth + 1, ans + arr[depth], max(mx, arr[depth])) % MOD + dfs(depth + 1, ans, mx);
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    ll ans = dfs(1, 0, 0) % MOD;
    cout << ans;
    return 0;
}
