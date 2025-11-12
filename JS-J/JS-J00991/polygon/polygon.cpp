#include<bits/stdc++.h>
#define int long long
using namespace std;
int n , a[5005] , ans , bsum[5005];
const int mod = 998244353;
void dfs(int deep , int sum , int mx){
    if(deep == n + 1){
        if(sum > 2 * mx){
            ans ++;
            ans %= mod;
        }
        return;
    }
    if(sum + bsum[deep] <= 2 * mx){
        return;
    }
    dfs(deep + 1 , sum + a[deep] , max(mx , a[deep]));
    if(sum + bsum[deep + 1] <= 2 * mx){
        return;
    }
    dfs(deep + 1 , sum , mx);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0);
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
    }
    for(int i = n ; i >= 1 ; i --){
        bsum[i] = bsum[i + 1] + a[i];
    }
    dfs(1 , 0 , 0);
    cout << ans;
    return 0;
}
