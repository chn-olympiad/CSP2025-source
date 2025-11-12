#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,cw,mi,www,w[10010][10010],ans,vis[10010][10010],g;
void dfs(int pos){
    if(pos==n+k+1){
    ans=0;
    for(int i=1;i<=n+k;i++){
        for(int j=i+1;j<=n+k;j++){
            if(vis[i][j]==1){
                g++;
                ans+=w[i][j];
            }
        }
    }
    if(g>=n){
    mi=min(ans,mi);}
    return;
    }
    for(int i=0;i<=1;i++){
        for(int j=pos;i<=n+k;i++){
            for(int f=pos+1;j<n+k;j++){
               vis[j][f]=i;
            }
        }
        dfs(pos+1);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>www;
        w[u][v]=www;

    }
    for(int i=1;i<=k;i++){
        cin>>cw;
        for(int j=1;j<=n;j++){
            cin>>www;
            w[i+n][j]=www+cw;
        }
    }
    dfs(1);
    cout<<mi;
    return 0;
}
