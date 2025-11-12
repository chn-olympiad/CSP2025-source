#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N][N];
void chus(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=1e9;
        }
    }
}
void jiab(int u,int v,int w){
    a[u][v]=a[v][u]=w;
}
void Dijstra(int vis[N]){
    //略
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    chus(n);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        jiab(u,v,w);
    }
    return 0;
}

