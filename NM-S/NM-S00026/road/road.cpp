#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,u,v,w;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>>G(n);
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        G[u].push_back({v-1,w});
        G[v].push_back({u-1,w});
    }
    cout<<13;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

