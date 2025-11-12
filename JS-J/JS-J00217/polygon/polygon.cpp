#include <bits/stdc++.h>
using namespace std;
int n, m, z, sum, cnt, mx;
int a[5010];
void dfs(int x, int y){
    if(x > z){
        if(sum > 2 * mx){
            cnt++;
            cnt = cnt % 998244353;
            return ;
        }
        return ;
    }
    for (int i = y + 1; i <= n - z + x; i++){
        sum += a[i];
        bool b = 0;
        int t = 0;
        if(mx > a[i]){
            b = 1;
        } else {
            t = mx;
            mx = a[i];
        }
        dfs(x + 1, i);
        sum -= a[i];
        if(!b){
            mx = t;
        }
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    bool o = 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != 1){
            o = 0;
        }
    }
    if(o){
        for (int i = 3; i <= n; i++){
            int e = 1, f = 1;
            for (int j = 1; j <= i; j++){
                e = e * (n - f + 1) / f % 998244353;
            }
            cnt = (cnt + e) % 998244353;
        }
        cout << cnt;
    }
    for (int i = 3; i <= n; i++){
        z = i;
        dfs(1, 0);
    }
    cout << cnt;
    return 0;
}
