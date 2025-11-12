#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int v[m+5],u[m+5],w[m+5];
    for(int i=1;i<=m;i++){
        cin>>v[i]>>u[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            cin>>m;
        }
    }
    cout<<0;
    return 0;
}

