#include<bits/stdc++.h>
using namespace std;

int n,m,k;

struct edge{
    int u,v,w;
};
vector<edge> E;
bool cmp(edge A,edge B){
    return A.w<B.w;
}

int fa[100005];
int find(int x){
    return (x==fa[x])?x:(fa[x]=find(fa[x]));
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        E.push_back(edge{u,v,w});
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            int x;
            cin>>x;
        }
    }
    sort(E.begin(),E.end(),cmp);
    int ans=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<m;i++){
        int u=E[i].u,v=E[i].v,w=E[i].w;
        if(find(u)==find(v)) continue;
        fa[find(u)]=find(v);
        ans+=w;
    }
    cout<<ans;
}