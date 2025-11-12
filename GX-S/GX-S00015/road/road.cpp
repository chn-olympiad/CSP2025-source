#include<bits/stdc++.h>
using namespace std;
int n,m,k,price[10000],parent[10000],ans,sum;
struct edge{
    int u,v,w;
}e[100000];
int a[10000][10000];
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int find(int x){
    if(x!=parent[x])
        x=find(parent[x]);
    return parent[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
        cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;++i){
        cin>>price[i];
        for(int j=1;j<=n;++j)
            cin>>a[j][i];
    }
    sort(e,e+m,cmp);
    for(int i=1;i<=n;++i)parent[i]=i;
    for(int i=1;i<=m;++i){
            if(sum==m)
            break;
        int u=find(e[i].u);
        int v=find(e[i].v);
        int w=e[i].w;
        cout<<w<" ";
        if(u==v)
        continue;
        ans+=w;
        parent[u]=v;
        sum++;
    }
    cout<<ans;
return 0;
}
