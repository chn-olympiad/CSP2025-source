#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+4;
int pt[N][N];
int c[114];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        pt[u][v]=w;
    }
    for(int i=1;i<=k;i++){

    }
    return 0;
}
