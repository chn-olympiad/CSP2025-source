#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int u,v,w;
    cin>>u>>v>>w;
    cout<<n*u+v*m+w*k;
    return 0;
}
