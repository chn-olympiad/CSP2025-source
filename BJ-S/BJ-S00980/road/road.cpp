#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long n,m,k;
int parent[maxn];
struct Edge{
    long long u,v,w;
    bool operator<(const Edge&e) const{
        return w<e.w;
    }
}edges[maxn];
long long find(long long x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}
long long kruskal(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    sort(edges,edges+m);
    int sum=0;
    int cnt=0;
    for(int i=0;i<m;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;
        int foot_u=find(u);
        int foot_v=find(v);
        if(foot_u!=foot_v){
        parent[foot_u]=foot_v;
        sum+=w;
        cnt++;
        if(cnt==n-1){
            break;
            }
        }
    }
    return sum;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i]={u,v,w};
    }
    for(int i=0;i<k;i++){
        int c1;
        cin>>c1;
        for(int j=0;j<n;j++){
            int k1;
            cin>>k1;
        }
    }
    int ans=kruskal();
    cout<<ans;
    return 0;
}

