#include<bits/stdc++.h>
#define int long long
using namespace std;
int n , k , a[500005] , ans;
void dfs(int deep , int sum , int dx , int emp){
    if(sum == k and !emp){
        sum = 0;
        emp = 1;
        dx ++;
    }
    if(deep > n){
        ans = max(ans , dx);
        return;
    }
    if(dx + n - deep < ans){
        return;
    }
    dfs(deep + 1, sum , dx , emp);
    dfs(deep + 1 , sum ^ a[deep] , dx , 0);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0);
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
    }
    dfs(1 , 0 , 0 , 1);
    cout << ans;
    return 0;
}
