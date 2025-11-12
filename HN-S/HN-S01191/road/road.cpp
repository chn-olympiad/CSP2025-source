#include<bits/stdc++.h>

const int M=1e6,K=10,N=1e4;

typedef long long int_64;

struct Edge{int u,v,w;}edges[M+N*K+5];
int c[K+5];
int n,m,k;

int fa[N+K+5],siz[N+K+5];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool merge(int x,int y)
{
    if((x=find(x))==(y=find(y)))return false;
    if(siz[x]>siz[y])std::swap(x,y);
    return fa[x]=y,true;
}

int_64 get_ans(int sta)
{
    int_64 res=0;
    int temp=0;

    for(int i=1;i<=k;++i)if(sta>>i-1&1)res+=c[i],++temp;
    for(int i=1;i<=n+k;++i)
        fa[i]=i,siz[i]=1;
    
    int sum=0;
    for(int i=1;i<=m;++i)
    {
        if(edges[i].u>n&&!(sta>>edges[i].u-n-1&1))continue;
        if(merge(edges[i].u,edges[i].v))
        {
            res+=edges[i].w;
            if(++sum==temp+n-1)break;
        }
    }

    return res;
}

bool checkA()
{
    for(int i=1;i<=k;++i)if(c[i])return false;
    return true;
}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);

    std::cin>>n>>m>>k;
    for(int i=1;i<=m;++i)std::cin>>edges[i].u>>edges[i].v>>edges[i].w;
    for(int i=1;i<=k;++i)
    {
        std::cin>>c[i];
        for(int j=1;j<=n;++j)
        {
            edges[++m]={n+i,j,0};
            std::cin>>edges[m].w;
        }
    }

    std::sort(edges+1,edges+1+m,[](const Edge &a,const Edge&b){return a.w<b.w;});

    const int STA=1<<k;

    if(checkA())return std::cout<<get_ans((1<<k)-1)<<'\n',0;

    int_64 ans=1e18;
    for(int i=0;i<STA;++i)
        ans=std::min(ans,get_ans(i));

    std::cout<<ans<<'\n';
    return 0;
}