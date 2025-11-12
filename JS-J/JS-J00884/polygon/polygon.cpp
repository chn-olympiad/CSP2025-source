#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int n, a[5005], ans;
bool vis[5005];
void dfs(int sum, int len, int ma){
    if(sum >= 2 * ma && len >= 3){
        ans++;
    }
    for(int i = 1; i <= n; i++){
        if(vis[i]){
            continue;
        }
        vis[i] = true;
        dfs(sum += a[i], len += 1, ma = max(ma, a[i]));
        vis[i] = false;
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dfs(a[1], 1, a[1]);
    cout << ans;
    return 0;
}
