#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w;
long long e[10010][10010],c[11][10010];
bool eisyes[10010][10010],jz[11],visyes[10010];
struct node{
    long long v;
    long long w;
}a;
bool cmp(node b,node c){
    return b.w<c.w;
}
long long bfs(long long v){
    vector<node>w0;
    for(int i=1;i<=n;i++)if(eisyes[v][i]){
        a.v=i;
        a.w=e[v][i];
        w0.push_back(a);
    }
    sort(w0,w0+w0.size(),cmp);

}
int main(){
    freopen("road1.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[u][v]=w;
        e[v][u]=w;
        eisyes[u][v]=1;
        eisyes[v][u]=1;
    }
    for(int i=1;i<=k;i++){
        long long sy=0;
        cin>>c[i][0];
        for(int j=1;j<=n;j++)cin>>c[i][j];
        for(int j=1;j<=n;j++)for(int l=j+1;l<=n;l++)if(c[i][j]+c[i][l]<e[i][j])sy+=e[i][j]-c[i][j]-c[i][l];
        if(sy>c[i][0]){
            jz[i]=1;
            for(int j=1;j<=n;j++)for(int l=j+1;l<=n;l++)if(eisyes[j][l]==1){
                e[j][l]=min(e[j][l],c[i][j]+c[i][l]);
                e[l][j]=min(e[l][j],c[i][j]+c[i][l]);
            }else{
                e[j][l]=c[i][j]+c[i][l];
                e[l][j]=c[i][j]+c[i][l];
                eisyes[j][l]=1;
                eisyes[l][j]=1;
            }
        }
    }
    bfs(1);
}
