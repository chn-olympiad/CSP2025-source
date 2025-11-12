#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int M=1e6+10;
int n,m,k,cnt;
int ans;
int num;
int c[N+10];
int fa[N+10];
bool vis[N];
struct edge{
    int u,v,w;
    bool operator < (const edge &x)const{
        return w<x.w;
    }
}e[2*(N*N+M)];
queue<edge>q;
int found(int x){
    return x==fa[x]?x:fa[x]=found(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>e[++cnt].u>>e[cnt].v>>e[cnt].w;
    }
    for(int j=1;j<=k;j++){
        cin>>c[n+j];
        for(int i=1;i<=n;i++){
            e[++cnt].u=n+j;
            e[cnt].v=i;
            cin>>e[cnt].w;
            e[cnt].w+=c[n+j];
        }
    }
    sort(e+1,e+cnt);
    //for(int i=1;i<=cnt;i++)cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
    for(int i=1;i<=cnt;i++){
        if(found(e[i].u)==found(e[i].v))continue;
        int u=e[i].u,v=e[i].v;
        if(u<=n&&!vis[u])num++;
        if(v<=n&&!vis[v])num++;
        vis[u]=1;
        ans-=c[u];
        vis[v]=1;
        ans-=c[v];
        if(u<v)swap(u,v);
        fa[found(u)]=found(v);
        ans+=e[i].w;
    }
    cout<<ans;
    return 0;
}
