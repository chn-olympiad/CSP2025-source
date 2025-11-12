#include <bits/stdc++.h>
using namespace std;
int a[20],vis[20],c[20];int n,m,ans; string s;
void dfs(int x) {
    if(x == n + 1) {
        int cnt = 0,r = 0;
        for(int i = 1;i <= n;i++) {
           // cout << a[i] << " ";
            if(r >= c[a[i]]) {r++; continue; }
            if(s[i - 1] == '1') cnt ++;
            if(s[i - 1] == '0') r++;
        }
        if(cnt >= m) ans ++;
       // cout << endl << cnt << endl;
        return ;
    }
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            a[x] = i;
            vis[i] = 1;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
     cin >> s;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    dfs(1);
    cout << ans ;
    return 0;
}
