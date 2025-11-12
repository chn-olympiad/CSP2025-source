#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5010;
const int mod = 998244353;
int n,a[MAXN],goal,ans = 0;
bool vis[MAXN];
void dfs(int x,int now){
    //for(int i = 1;i <= n;i++){
    //    if(vis[i]) cout << 1 << " ";
    //    else cout << 0 << " ";
    //}
    //cout << endl;
    if(x == goal + 1){
        int maxn = 0,sum = 0;
        for(int i = 1;i <= n;i++){
            if(vis[i]) maxn = max(maxn,a[i]),sum += a[i];
        }
        if(sum > 2 * maxn){
            //for(int i = 1;i <= n;i++){
            //    if(vis[i]) cout << a[i] << " ";
            //}
            //cout << endl;
            ans++;
            ans %= mod;
        }
        return;
    }
    for(int i = now + 1;i <= n;i++){
        if(!vis[i]){
            vis[i] = true;
            dfs(x + 1,i);
            vis[i] = false;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 3;i <= n;i++){
        memset(vis,0,sizeof(0));
        goal = i;
        dfs(1,0);
    }
    cout << ans << endl;
    return 0;
}
