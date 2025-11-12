#include <bits/stdc++.h>
using namespace std;
int n, m, s[505], c[505], cc__[505];
bool vis[505];
long long annnnns = 0;
void dfs(int cur){
    if (cur == n + 1){
        int cnttt = 0, suum = 0;
        for (int i = 1; i <= n; i++){
            int j = cc__[i];
            if (cnttt >= c[j]){
                cnttt++;
                continue;
            }
            if (s[i] == 0) cnttt++;
            else cnttt = 0, suum++;
        }
        if (suum >= m) annnnns = (annnnns + 1) % 998244353;
//        cout << annnnns << "\n";
        return;
    }
    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        cc__[cur] = i;
        dfs(cur + 1);
        vis[i] = 0;
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    bool flaaaaaaaaaag = 1;
    for (int i = 1; i <= n; i++){
        char tmpppc;
        cin >> tmpppc;
        s[i] = tmpppc - '0';
        if (s[i] == 0) flaaaaaaaaaag = 0;
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    if (flaaaaaaaaaag){
        long long ans = 1;
        for (int i = n; i >= 1; i--){
            ans *= i;
            ans %= 998244353;
        }
        cout << ans;
        return 0;
    }
    for (int i = 1; i <= n; i++) vis[i] = 0;
    dfs(1);
    cout << annnnns;
    return 0;
}
