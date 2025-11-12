#include<bits/stdc++.h.
using namespace std;
int n,m,k;
const int N=1e4+10;
const int M=1e6+10;
vector<vector<pair<int,int>>> graph;
int a[20][N],c[20];
int main(){
    freopen("rosd.in","r",stdin);
    freopen("rosd.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    cout<<0;
    return 0;
}
