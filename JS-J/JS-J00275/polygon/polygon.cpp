#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, ans = 0, cnt = 0;
int a[5050];
int sum = 0, mx = -1e9;
void dfs(int id, int f){
    if(id < n){
        int nid = id + 1, lmx = mx;
        if(f == 0){
            dfs(nid, 0);
            dfs(nid, 1);
            sum -= a[nid];
            cnt--;
            mx = lmx;
            return ;
        }
        else {
            cnt++;
            sum += a[id];
            mx = max(mx, a[id]);
            dfs(nid, 0);
            dfs(nid, 1);
            sum -= a[nid];
            cnt--;
            mx = lmx;
            return ;
        }
    }
    else {
        if(f == 0){
            if(cnt >= 3){
                if(sum > 2 * mx){
                ans++;
                ans %= mod;
                }
            }
            return ;
        }
        else {
            cnt++;
            sum += a[id];
            mx = max(mx, a[id]);
            if(cnt >= 3){
                if(sum > 2 * mx){
                ans++;
                ans %= mod;
                }
            }
            return;
        }
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dfs(1, 0);
    mx = -1e9;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}
