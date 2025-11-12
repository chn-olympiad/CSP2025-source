#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];

bool fa[10001][10001];

long long ans=100000000;
int n,m,k;
void bfs(int nz,bool f[10001],int cost){
    bool g=1;
    for(int ii=1;ii<=n;ii++){
        if(f[ii]==0){
            for(int i=1;i<=n;i++){
                if(fa[nz][i]){
                    if(f[i]==0){
                        f[i]=1;
                        bfs(i,f,cost+a[nz][i]);
                        f[i]=0;
                    }
                }

            }
            g=0;
            break;
        }
    }
    if(g){
        ans=min(ans,(long long)cost);
    }

}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0){
    for(int i=1;i<=m;i++){

        int u,v,w;
        cin>>u>>v>>w;
        fa[u][v]=1;
        fa[v][u]=1;
        a[u][v]=a[v][u]=w;}

    //开始寻找最段路
    bool f[10001];
    for(int i=1;i<=n;i++) f[i]=0;
    f[1]=1;
    bfs(1,f,0);
    cout<<ans;
    
    }
    else cout<<0;



    return 0;

}
