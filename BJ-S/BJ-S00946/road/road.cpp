#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+20,M=1e6+1e5+10,K=10+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,k;
struct node
{
    ll u,v,w;
}e[M];
bool cmp(node x,node y){return x.w<y.w;}
ll cnt;
ll c[K],r[K][N];
bool flag=1;
ll fa[N];
void binit(ll x)
{
    for(ll i=1;i<=x;i++) fa[i]=i;
}
ll findf(ll x)
{
    if(fa[x]==x) return x;
    return fa[x]=findf(fa[x]);
}
namespace Sol1
{
    void solve1()
    {
        binit(n);
        sort(e+1,e+cnt+1,cmp);
        ll ans=0;
        for(ll i=1;i<=cnt;i++)
        {
            ll fx=findf(e[i].u),fy=findf(e[i].v);
            if(fx!=fy)
            {
                fa[fx]=fy;
                ans+=e[i].w;
            }
        }
        cout<<ans<<endl;
    }
};
namespace Sol3
{
    node ee[M];
    void solve3()
    {
        ll lim=1<<k,ans=inf;
        sort(e+1,e+cnt+1,cmp);
        for(ll s=0;s<lim;s++)
        {
            ll res=0,ecnt=0;
            for(ll i=0;i<k;i++)
            {
                if(s&(1<<i))
                {
                    res+=c[i+1];
                    for(ll j=1;j<=n;j++)
                    {
                        ee[++ecnt]={n+i+1,j,r[i+1][j]};
                    }
                }
            }
            binit(n+k);
            sort(ee+1,ee+ecnt+1,cmp);
            ll it=1,jt=1;
            while(it<=cnt && jt<=ecnt)
            {
                if(e[it].w<ee[jt].w)
                {
                    ll fx=findf(e[it].u),fy=findf(e[it].v);
                    if(fx!=fy)
                    {
                        fa[fx]=fy;
                        res+=e[it].w;
                    }
                    it++;
                }
                else
                {
                    ll fx=findf(ee[jt].u),fy=findf(ee[jt].v);
                    if(fx!=fy)
                    {
                        fa[fx]=fy;
                        res+=ee[jt].w;
                    }
                    jt++;
                }
            }
            while(it<=cnt)
            {
                ll fx=findf(e[it].u),fy=findf(e[it].v);
                if(fx!=fy)
                {
                    fa[fx]=fy;
                    res+=e[it].w;
                }
                it++;
            }
            while(jt<=ecnt)
            {
                ll fx=findf(ee[jt].u),fy=findf(ee[jt].v);
                if(fx!=fy)
                {
                    fa[fx]=fy;
                    res+=ee[jt].w;
                }
                jt++;
            }
            ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        e[++cnt]={u,v,w};
    }
    for(ll i=1;i<=k;i++)
    {
        bool pd=0;
        cin>>c[i];
        if(c[i]) flag=0;
        for(ll j=1;j<=n;j++)
        {
            cin>>r[i][j];
            if(!r[i][j]) pd=1;
        }
        if(!pd) flag=0;
    }
    if(k==0)
    {
        // cerr<<"First"<<endl;
        Sol1::solve1();
    }
    else if(flag)
    {
        // cerr<<"Second"<<endl;
        for(ll i=1;i<=k;i++)
        {
            ll pos=0;
            for(ll j=1;j<=n;j++)
                if(r[i][j]==0)
                    pos=j;
            assert(pos);
            for(ll j=1;j<=n;j++)
            {
                if(j!=pos)
                {
                    e[++cnt]={pos,j,r[i][j]};
                }
            }
        }
        Sol1::solve1();
    }
    else
    {
        // cerr<<"Third"<<endl;
        Sol3::solve3();
    }
    return 0;
}