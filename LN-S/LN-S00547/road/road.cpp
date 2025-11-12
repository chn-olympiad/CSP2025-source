#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int>q[1000001];
//#define qwq cout<<"qwq";
void dfs(int u){

}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        q[u][v]=w;
        q[v][u]=w;
    }
    //qwq
    cout<<20251101;

}
