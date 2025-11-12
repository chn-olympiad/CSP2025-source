#include <bits/stdc++.h>
using namespace std;
#define int long long
int fa[100005];
int find_(int x)
{
    int fath=fa[x];
    if(fath==x)
    {
        return x;
    }
    fa[x]=find_(fath);
    return fa[x];
}
void union_(int x,int y)
{
    int tx=find_(x);
    int ty=find_(y);
    cout<<tx<<" "<<ty<<endl;
    if(tx==ty)
    {
        return;
    }
    fa[tx]=ty;
}
struct Node{
    int u,v,w;
};
int cnt;
Node e[100005];
bool cmp(Node x,Node y)
{
    return x.w<y.w;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    cout<<n;
    for(int i=1;i<=n+k;++i)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        e[++cnt]={u,v,w};
    }
    for(int i=1;i<=k;++i)
    {
        int c;
        scanf("%lld",&c);
        for(int j=1;j<=n;++j)
        {
            int w;
            scanf("%lld",&w);
            e[++cnt]={n+i,j,w};
        }
    }
    sort(e+1,e+m+1,cmp);
    int ans=0;
    for(int i=1;i<=cnt;++i)
    {
        if(find_(e[i].u)!=find_(e[i].v))
        {
            ans+=e[i].w;
            union_(e[i].u,e[i].v);
        }
    }
    printf("%lld",ans);
    return 0;
}
