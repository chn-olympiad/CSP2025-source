#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
    int u,v,w,x;
    bool operator <(const edge tmp)const
    {
        return w<tmp.w;
    }
}e[1010100],ee[110010];
//怎么是Kruscal板子题。
//逆天
int f[10020];
int c[12];
inline int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
int n,m,k;
void ini()
{
    for(int i=1;i<=n+k;i++)
        f[i]=i;
}
int cnt=0;

signed main()
{
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e+1,e+1+m);//密码的这个错误(m->n)给我调半天
    ini();
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        if(find(e[i].u)!=find(e[i].v))ans+=e[i].w,f[find(e[i].u)]=find(e[i].v),ee[++cnt]=e[i];
    }
    clog<<ans<<'\n';
    for(int i=0;i<k;i++)
    {
        cin>>c[i];
        for(int x=1;x<=n;x++)
        {
            int t;cin>>t;
            ee[++cnt]=(edge){n+i+1,x,t,i+1};
        }
    }
    sort(ee+1,ee+1+cnt);
    // for(int i=1;i<=cnt;i++)clog<<ee[i].u<<' '<<ee[i].v<<' '<<ee[i].w<<' '<<ee[i].x<<'\n';
    for(int i=1;i<(1<<k);i++)
    {
        long long now=0;
        for(int x=0;x<k;x++)
            now+=c[x]*((i>>x)&1);
        ini();
        // clog<<i<<' '<<now<<'\n';
        for(int q=1;q<=cnt;q++)
        {
            if(ee[q].x&&(((i>>(ee[q].x-1))&1)==0))continue;
            if(find(ee[q].u)!=find(ee[q].v))now+=ee[q].w,f[find(ee[q].u)]=find(ee[q].v);
        }
        // for(int q=1;q<=n;q++)
        //     assert(find(q)==find(1));
        ans=min(ans,now);
    }
    cout<<ans<<'\n';
    return 0;
}
//666看错了以为是城镇与城镇间连边