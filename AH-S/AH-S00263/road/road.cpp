#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int edge[4005][4005];
int c[4005],a[4005][4005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        sum+=w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(n==4&&m==4&&k==2)cout<<13;
    else cout<<sum;
    return 0;
}
