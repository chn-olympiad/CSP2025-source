#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int z=0,u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        z+=w;
    }
    cout<<z;
    return 0;
}
