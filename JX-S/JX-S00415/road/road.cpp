#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int num;
int f[10001][10001];
int c[11];
int a[12][10001];
int fa[10001];
int find(int x){
    if(fa[x]==x){
        return x;
    }
    else return x=find(fa[x]);
}
void add(int x,int y){
   fa[y]=x;
}
bool cmp(){
    for(int i=1;i<=n;i++){
       if(find(i)!=find(1)){
           return 0;
       }
    return 1;
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]==-1;
        }
    }
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        f[u][v]=f[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            //if(find(i)==find(y)){
                //continue;
            //}
            for(int i=1;i<=n;i++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    cout<<f[1][2];
    return 0;
}
