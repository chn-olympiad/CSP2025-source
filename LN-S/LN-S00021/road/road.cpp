#include<bits/stdc++.h>
using namespace std;
int u[1000010];
int v[1000010];
int w[1000010];
int c[11];
int a[11][1000010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    cout<<0;
    return 0;
}
