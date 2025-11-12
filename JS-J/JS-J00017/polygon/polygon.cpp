#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3;
int n;
int a[N + 5];
bool vis[N + 5];
int ans = 0, mod = 998244353;
bool flag = true;
void dfs(int x){
    if(x == n + 1){
        int cnt = 0, sum = 0, maxn = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i]){
                //cout << i << " ";
                cnt++;
                sum += a[i];
                maxn = max(a[i], maxn);
            }
        }
        if(cnt >= 3 && sum > 2 * maxn){
            ans = (ans % mod + 1) % mod;
        }
        //cout << cnt << " " << sum << " " << maxn << " " << ans << endl;
        return ;
    }
    dfs(x + 1);
    vis[x] = true;
    dfs(x + 1);
    vis[x] = false;
}
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != 1) flag = false;
    }
    if(flag){
        for(int i = 3; i <= n; i++){
            int k = n - i, s = 1;
            for(int j = 1; j <= k; j++){
                s = (s * 2) % mod;
            }
            ans = (ans + 1 + (s - 1) * i % mod) % mod;
            //cout << ans << endl;
        }
        cout << ans;
        return 0;
    }
    ans = 0;
    dfs(1);
    cout << ans;
    return 0;
}
