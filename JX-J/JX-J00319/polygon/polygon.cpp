#include<bits/stdc++.h>
using namespace std;

const int N = 1E6 + 10;
int n;
int a[N];
int ans = 0;
void dfs(int i, int sum, int maxl){
    if(i > n){
        if(sum > maxl * 2){
            ans = (ans + 1) % 998244353;
        }
        return ;
    }
    dfs(i + 1, sum, maxl);
    dfs(i + 1, sum + a[i], max(maxl, a[i]));
}
int c(int x, int y){
    int sum = 1;
    for(int i = 1, j = x;i <= y;i++, j--){
        sum = (sum * j) % 998244353;
    }
    int dsum = 1;
    for(int i = 1;i <= y;i++){
        dsum = (dsum * i) % 998244353;
    }
    return sum / dsum;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    bool f = true;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] > 1){
            f = false;
        }
    }
    if(f){
        int cnt = 0;
        for(int i = 4;i <= n;i++){
            cnt = (cnt + c(n, i)) % 998244353;
        }
        cout << cnt;
        return 0;
    }
    dfs(1, 0, 0);
    cout << ans % 998244353;
    return 0;
}
