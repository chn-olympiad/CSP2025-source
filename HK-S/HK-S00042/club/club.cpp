#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans = 0;
vector<vector<int>> a;

void dfs(int n, int u, int n1, int n2, int n3, int an){
    if(u == n){
        ans = max(ans, an);
        return;
    }
    if(n1+1 <= n/2) dfs(n, u+1, n1+1, n2, n3, an+a[u][0]);
    if(n2+1 <= n/2) dfs(n, u+1, n1, n2+1, n3, an+a[u][1]);
    if(n3+1 <= n/2) dfs(n, u+1, n1, n2, n3+1, an+a[u][2]);
    return;
}

void solve(){
    int n;
    a.clear();
    cin >> n;
    for(int i=0;i<n;i++){
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        a.push_back({a1, a2, a3});
    }
    if(n == 2){
        int ans = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i == j) continue;
                ans = max(ans, a[0][i] + a[1][j]);
            }
        }
        cout << ans << '\n';
    } else if(n <= 10){
        ans = 0;
        dfs(n, 0, 0, 0, 0, 0);
        cout << ans << '\n';
    }
    return;
    // for(auto x:a){
    //     cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
    // }

}


int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}