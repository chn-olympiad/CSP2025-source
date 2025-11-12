#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+114,M=1e6+114;
int n,m,k,cnt,ans,a[1145],dis[1145][1145];
struct edge{
    int u,v,w;
    bool operator<(const edge &x){
        return w<x.w;
    }
}e[M];
struct UFset{
    int f[N];
    void init(){
        for(int i=1;i<=n;i++) f[i]=i;
    }
    int find(int x){
        if(f[x]==x) return x;
        return f[x]=find(f[x]);
    }
}S;
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+1+m);
    S.init();
    for(int i=1;i<=m;i++)
    {
        int fu=S.find(e[i].u),fv=S.find(e[i].v);
        if(fu!=fv){
            ans+=e[i].w;
            S.f[fv]=fu;
            if(++cnt==n-1) break;
        }
    }
    cout<<ans;
    return 0;
}
