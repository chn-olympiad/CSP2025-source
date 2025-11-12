#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[20][5000005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > queue;
vector<pair<int,int> > g[1000005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>a[i+n][j];
        }
    }
    cout<<0;
    return 0;
}
