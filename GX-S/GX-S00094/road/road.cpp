#include<bits/stdc++.h>
using namespace std;
struct road{
int u;
int v;
int w;
};
int main(){
    int a[10][1000];
    road b[100000];
    int c[10];
    int connect[1000][1000];
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long ans=0;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>b[i].u>>b[i].v>>b[i].w;
        //ans+=b[i].w;
        //connect[b[i].u][b[i].v]=1;
        //connect[b[i].v][b[i].u]=1;
    }
    for(int i=0;i<m;i++){
        cin>>c[i];
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        ans+=b[i].w;
        for(int j=0;j<n;j++){
            if(connect[b[i].u][b[i].v]>0||connect[b[i].u][j]&&connect[b[i].v][j]&&b[i].w>connect[b[i].u][j]+connect[b[i].v][j]){
                ans-=b[i].w;
                connect[b[i].u][b[i].v]=min(connect[b[i].u][j]+connect[b[i].v][j],connect[b[i].u][b[i].v]);
                connect[b[i].v][b[i].u]=min(connect[b[i].u][j]+connect[b[i].v][j],connect[b[i].v][b[i].u]);
            }else if(connect[b[i].u][j]&&connect[b[i].v][j]==0){
                connect[b[i].v][j]=b[i].w+connect[b[i].u][j];
            }else if(connect[b[i].v][j]&&connect[b[i].u][j]==0){
                connect[b[i].u][j]=b[i].w+connect[b[i].v][j];
            }
        }
        if(connect[b[i].u][b[i].v]==0){
            connect[b[i].u][b[i].v]=b[i].w;
            connect[b[i].v][b[i].u]=b[i].w;
        }
    }
    cout<<ans;
    return 0;
}
