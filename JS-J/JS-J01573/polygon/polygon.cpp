#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[5010];
int ans = 0;

void dfs(int u , int k , int sum , int lz , int cnt){
    if(u == k + 1){
        if(sum > 2 * lz && cnt >= 3){
            ans++;
            ans %= 998244353;
        }
        return;
    }
    dfs(u + 1 , k , sum + a[u] , max(lz , a[u]) , cnt + 1);
    dfs(u + 1 , k , sum , lz , cnt);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1 , n , 0 , 0 , 0);
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
