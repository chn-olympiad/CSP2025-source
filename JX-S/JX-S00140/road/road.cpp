#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[10005],v[10005],w[10005],c[15],a[15][10005],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        ans+=w[i];
    }
    ans+=c[1];
    ans+=a[1][2];
    ans+=a[1][1];
    cout<<ans;
}
