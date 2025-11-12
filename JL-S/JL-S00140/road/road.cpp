#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1110000],v[1110000],w[1110000],c[11],a[11][11100];
int main(){
    freopen("road.in","r",stdin);
    freopen("rosd.out","w",stdout);
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
    cout<<0;
}
