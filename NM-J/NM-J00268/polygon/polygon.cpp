#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[5010];
void dfs(int x, int cnt, int sum, int lt, int ltt){
    if(x > cnt){
        if(sum > lt*2){
            ans++;
            ans%=998244353;
        }
        return ;
    }
    for(int i = 1+ltt;i <= n;i++){
        dfs(x+1, cnt, sum+a[i], a[i], i);
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(&a[1], &a[n+1]);
    for(int i = 3;i <= n;i++){
        dfs(1, i, 0, 0, 0);
    }
    cout << ans;
    return 0;
}
