#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[5010];
int ans = 0;
bool vis[5010];
void dfs(int b,int mb,int tot,int maxn,int h){
    if(b == mb){
        if(tot > maxn * 2){ans ++;
        ans %= mod;}
        return;
    }
    for(int i = 1; i <= n; ++ i){
        if(vis[i] and a[i] >= maxn and i > h){
            vis[i] = 0;
            dfs(b + 1,mb,tot + a[i],a[i],i);
            vis[i] = 1;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= 5000; ++ i)
        vis[i] = 1;
    for(int i = 1; i <= n;++ i)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 3; i <= n;++ i){
        dfs(0,i,0,0,0);
    }
    cout << ans;
    return 0;
}
