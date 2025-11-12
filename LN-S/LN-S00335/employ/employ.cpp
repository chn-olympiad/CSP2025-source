#include <bits/stdc++.h>
using namespace std;
string k;
int n,m,a[1000005],ans,vis[100005];
void dfs(int rt,int sum,int goaway){
    if(rt == k.size()){
        if(sum == m) ans = (ans+1)%998244353;
        return ;
    }
    for(int i = 1;i <= n;i++){
        if(vis[i] == 0 && a[i] < goaway && k[rt] == '1'){
            vis[i] = 1;
            dfs(rt+1,sum+1,goaway);
            vis[i] = 0;
        }
        dfs(rt+1,sum.goaway+1);
    }
}
int main(){
    freopen("empoly.in","r",stdin);
    freopen("empoly.out","w",stdout);
    cin >. n >> m;
    cin >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dfs(1,0,0);
    cout << ans<< endl;
}