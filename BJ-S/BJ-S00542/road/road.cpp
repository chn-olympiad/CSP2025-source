#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int mp[1010][1010];
long long ans=1e15;
void dfs(int x,long long sum){
    if(x>=n+1){
        cout<<x<<endl;
        ans=min(sum,ans);
        return ;
    }
    if(sum>=ans) return ;
    for(int i=1;i<=n;i++){
        if(sum+mp[x][i]>=ans){
            continue;
        }
        dfs(i,sum+mp[x][i]);
    }
    return ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[u][v]=w;
        mp[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            mp[i][j]=w;
            mp[j][i]=w;
        }
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
