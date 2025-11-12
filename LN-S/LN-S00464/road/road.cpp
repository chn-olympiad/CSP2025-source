#include <bits/stdc++.h>
using namespace std;
struct Node{
    int u,v,w;
    friend bool operator<(Node a,Node b){
        return a.w<b.w;
    }
};
int nd[10010][10010];
vector<Node>edge;
int n,m,k;
int a[15][10010];
int fa[10010];
int find(int u){
    if(fa[u]==u)return u;
    else return find(fa[u]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
        nd[u][v]=w;
        //edge.push_back({v,u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>a[i][0];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(nd[u][v]>a[i][j])edge.push_back({i,j,a[i][j]});
        }
    }
    for(int i=1;i<=n;i++){fa[i]=i;}
    sort(edge.begin(),edge.end());
    int idx=0,ans=0;
    for(int cnt=1;cnt<=n-1;){
        int u=edge[idx].u,v=edge[idx].v,w=edge[idx].w;
        //cout<<u<<' '<<v<<' '<<w<<endl;
        if(find(u)!=find(v)){
            ans+=w;cnt++;
            fa[v]=find(u);
        }idx++;
    }cout<<ans<<endl;
    return 0;
}
/*
6 7 5 4 
10 9 4 3 1
*/