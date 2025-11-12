#include<bits/stdc++.h>
using namespace std;
#define fileio
#define IOS
void ___()
{
#ifdef fileio
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
#endif
#ifdef IOS
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    #define endl '\n'
#endif
}
#define ll long long
const int _mxn=1e4+5;
struct graph
{
    typedef ll w_type;
    struct node
    {
        int v;
        w_type w;
        node(){}
        node(int _v,w_type _w):v(_v),w(_w){}
        bool operator<(node _x) const {return w<_x.w;}
        bool operator>(node _x) const {return w>_x.w;}
    };
    struct edge
    {
        int u,v;
        w_type w;
        edge(){}
        edge(int _u,int _v,w_type _w):u(_u),v(_v),w(_w){}
        bool operator<(edge _x) const {return w<_x.w;}
        bool operator>(edge _x) const {return w>_x.w;}
    };
    // vector<node> g[_mxn];
    vector<edge> e;
    void add(int u,int v,w_type w)
    {
        // g[u].push_back(node(v,w));
        e.push_back(edge(u,v,w));
    }
}g,t,tr;
struct dsu
{
    int f[_mxn];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            f[i]=i;
    }
    int find(int x)
    {
        if(f[x]==x)
            return x;
        return f[x]=find(f[x]);
    }
    void merge(int x,int y)
    {
        int fx=find(x),fy=find(y);
        f[fy]=fx;
    }
    bool same(int x,int y){return find(x)==find(y);}
};
int n,m,k;
ll c[20],a[20][_mxn];
ll ans=1e18,s;
ll kruskal(graph g,int n,bool totr=false)
{
    dsu t;
    t.init(n+k);
    sort(g.e.begin(),g.e.end());
    ll res=0;
    int cnt=0;
    for(auto it:g.e)
    {
        if(!t.same(it.u,it.v))
        {
            t.merge(it.u,it.v);
            res+=it.w;
            if(res+s>=ans)
                return 1e18;
            cnt++;
            if(totr)
                tr.add(it.u,it.v,it.w);
        }
        if(cnt==n-1)
            break;
    }
    if(cnt<n-1)
        return 1e18;
    return res;
}
int main()
{
    ___();
    // clock_t t1=clock();
    cin>>n>>m>>k;
    while(m--)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        g.add(u,v,w);
    }
    ans=kruskal(g,n,true);
    for(int j=1;j<=k;j++)
    {
        cin>>c[j];
        for(int i=1;i<=n;i++)
            cin>>a[j][i];
    }
    for(int x=0;x<(1<<k);x++)
    {
        t=tr;
        s=0;
        for(int j=0;j<k;j++)
        {
            if((x>>j)&1)
            {
                s+=c[j+1];
                if(s>=ans)
                    break;
                for(int i=1;i<=n;i++)
                    t.add(n+j+1,i,a[j+1][i]);
            }
        }
        if(s>=ans)
            continue;
        s+=kruskal(t,n+__builtin_popcount(x));
        ans=min(ans,s);
    }
    cout<<ans<<endl;
    // cerr<<clock()-t1;
    return 0;
}

/*
迷惑行为，启动！

你说你不想在这里
我也不想在这里
但天黑得太快想走早就来不及
哦我爱你
可惜关系变成没关系
问题是没问题
于是我们继续
拿着笔 想写点东西
以为是武器能声张 正 义！
没人理 也没关系
至少我还有你
至少我还有
你说你不想在这里
我也不想在这里
但天黑得太快想走早就来不及
哦我爱你
可惜关系变成没关系
问题是没问题
于是我们继续
*/