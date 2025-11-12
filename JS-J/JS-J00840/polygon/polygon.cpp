#include <bits/stdc++.h>
using namespace std;
int n,a[5002],ans,cnt;
bool vis[5002];
void dfs(int dep,int maxx,int sum,int up){
    if(dep>=3&&maxx*2<sum){
        ans++;
    }
    for(int i=up+1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            dfs(dep+1,max(maxx,a[i]),sum+a[i],i);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0,0);
    cout<<ans%998244353<<endl;
    return 0;
}
