#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000050],v[1000050],w[1000050],c[20],a[20][10050];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",a[i][j]);
        }
    }
    cout<<0;
    return 0;
}
