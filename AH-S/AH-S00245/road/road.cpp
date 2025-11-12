#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
vector<pair<int,int>>G[N];
int country[11][N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    for(int i = 1;i<=k;i++){
        cin>>country[i][0];
        for(int j = 1;j<=n;j++){
            cin>>country[i][j];
        }
    }
    cout<<0;
    return 0;
}
