#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,e[10005][10005],ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        e[u][v]=w;
        e[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            scanf("%lld",&w);
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(e[i][k]!=0&&e[k][j]!=0&&e[i][j]!=0){
                    e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=e[i][j];
        }
    }
    cout<<ans/n;
    return 0;
}
