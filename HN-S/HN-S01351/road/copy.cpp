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
template<typename T>
inline void read(T &x)
{
    x=0;bool w=0;
    char ch=getchar();while(ch<'0'||ch>'9'){w|=ch=='-';ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=(w?~x+1:x);
}
int main(){
    freopen("road3.in","r",stdin);
    // freopen("road.out","w",stdout);

    int n,m,k;
    read(n);read(m);read(k);
    vector<edge>e(m);
    for(auto &[u,v,w]: e)
    {
        read(u);
        read(v);
        read(w);
    }
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
    vector<vector<int>>g(k+1,vector<int>(n+1));
    vector<int>cost(k+1);
    for(int i=1;i<=k;i++)
    {
        read(cost[i]);
        for(int j=1;j<=n;j++)
            read(g[i][j]);
    }
    sort(use.begin(),use.end(),[&](const edge &e1,const edge &e2){
        return e1.w<e2.w;
    });
    long long ans=0;
    for(auto &[u,v,w]: use)
        ans+=w;
    vector<int>c(n+1),idx(n);
    for(int sta=1;sta<(1<<k);sta++)
    {
        long long base=0;
        fill(c.begin(),c.end(),1e9);
        iota(idx.begin(),idx.end(),1);
        for(int i=0;i<k;i++)
            if((sta>>i)&1)
            {
                base+=cost[i+1];
                for(int j=1;j<=n;j++)
                    c[j]=min(c[j],g[i+1][j]);
            }
        D.init(n+1);
        vector<edge>nw;
        sort(idx.begin(),idx.end(),[&](const int &x,const int &y){
            return c[x]<c[y];
        });
        for(int i=0,p=0;i<n-1;i++)
        {
            while(p<n&&c[idx[p]]<use[i].w)
            {
                nw.push_back({idx[p],n+1,c[idx[p]]});
                p++;
            }
            nw.push_back(use[i]);
        }
        for(auto &[u,v,w]: nw)
            if(!D.same(u,v))
            {
                base+=w;
                D.merge(u,v);
            }
        ans=min(ans,base);
        cout<<sta<<" "<<base<<endl;
    }
    printf("%lld\n",ans);

    return 0;
}