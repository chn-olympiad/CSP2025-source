#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool vis[5005];
int n,ans,fans,maxn;
const int mod = 998244353;
void dfs(int dep, int x, int lst){
    if(dep == x){
        if(maxn == 1){
            ans++;
            ans %= mod;
            return ;
        }
        /*for(int i = 0; i < n; i++){
            cout << vis[i] << " ";
        }
        cout << "\n";*/
        int sum = 0, maxn = 0;
        for(int i = 0; i < n; i++){
            if(vis[i]) {
                sum += a[i];
                maxn = max(maxn,a[i]);
            }
        }
        if(sum > 2*maxn){
            ans++;
            ans %= mod;
            return ;
        }
    }else{
        for(int i = lst; i < n; i++){
            if(!vis[i]){
                vis[i] = 1;
                dfs(dep+1,x,i);
                vis[i] = 0;
            }
        }
    }    
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    if(n <= 3){ //#1-3
        int maxn = max({a[0],a[1],a[2]});
        int sum = a[0] + a[1] + a[2];
        if(sum > 2*maxn) cout << 1;
        else cout << 0;
        return 0;
    }else if(n > 3 && n <= 20){ // # 4-10
        for(int i = 3; i <= n; i++){
            ans = 0;
            dfs(0,i,0);
            //cout << ans << "\n";
            fans += ans;
        }
        cout << fans << "\n";
        return 0;
    }

    return 0;
}