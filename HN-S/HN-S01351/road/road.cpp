#include<bits/stdc++.h>
using namespace std;
class DSU{
    private:
        vector<int>fa,sz;
        inline int find(const int &x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    public:
        inline void init(int n){fa.resize(n+1);sz.resize(n+1);iota(fa.begin(),fa.end(),0);fill(sz.begin(),sz.end(),1);}
        inline void merge(int u,int v){u=find(u);v=find(v);if(u==v) return;if(sz[u]<sz[v]) swap(u,v);fa[v]=u;sz[u]+=sz[v];}
        inline bool same(int u,int v){return find(u)==find(v);}
};
struct edge{
    int u,v,w;
};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    vector<edge>e(m);
    for(auto &[u,v,w]: e)
        scanf("%d %d %d",&u,&v,&w);
    sort(e.begin(),e.end(),[&](const edge &e1,const edge &e2){
        return e1.w<e2.w;
    });
    DSU D;
    D.init(n);
    vector<edge>use;
    for(auto &p: e)
    {
        if(D.same(p.u,p.v))
            continue;
        else
        {
            use.push_back(p);
            D.merge(p.u,p.v);
        }
    }
    vector<int>cost(k+1);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&cost[i]);
        for(int j=1;j<=n;j++)
        {
            int w;
            scanf("%d",&w);
            use.push_back({n+i,j,w});
        }
    }
    sort(use.begin(),use.end(),[&](const edge &e1,const edge &e2){
        return e1.w<e2.w;
    });
    vector<DSU>F(1<<k);
    for(int i=0;i<(1<<k);i++)
        F[i].init(n+k);
    vector<long long>res(1<<k);
    for(int sta=0;sta<(1<<k);sta++)
    {
        long long val=0;
        for(int i=0;i<k;i++)
            if((sta>>i)&1)
                val+=cost[i+1];
        res[sta]=val;
    }
    for(auto &[u,v,w]: use)
    {
        if(u<=n)
        {
            for(int s=0;s<(1<<k);s++)
                if(!F[s].same(u,v))
                {
                    F[s].merge(u,v);
                    res[s]+=w;
                }
        }
        else
        {
            int mr=u-n-1;
            for(int s=0;s<(1<<k);s++)
            {
                if(!((s>>mr)&1))
                    continue;
                if(!F[s].same(u,v))
                {
                    F[s].merge(u,v);
                    res[s]+=w;
                }
            }
        }
    }
    long long ans=*min_element(res.begin(),res.end());
    printf("%lld\n",ans);

    return 0;
}