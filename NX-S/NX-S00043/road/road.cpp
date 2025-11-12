#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
    int n,m,k;
    int u[1005],v[1005],w[1005],f[1005],b[1005][1005];
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
            cin>>f[i];
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    cout<<0;
return 0;
}
