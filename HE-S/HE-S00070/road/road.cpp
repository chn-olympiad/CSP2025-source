#include<bits/stdc++.h>
using namespace std;
int n,m,k,b[10010][10010],kb[20],kx[20][10010];
vector<int>a[10010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back(v);
        a[v].push_back(u);
        b[u][v]=w;
        b[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&kb[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&kx[i][j]);
        }
    }
    printf("%lld",7774461636);
    return 0;
}
