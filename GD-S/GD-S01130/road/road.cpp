#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(#x".in","r",stdin)
#define fout(x) freopen(#x".out","w",stdout)
#define file(x) (fin(x),fout(x),0)

int xxxx=file(road);

const int maxm=1e6+100,maxn=1e4+100,maxk=2e5+100;

ll ans;

int n,m,k,cntad;
int fa[maxn],c[15];

bool cis[15];

pair<int,pii>edge[maxm],UE[maxn],ad[maxk],tmp1[maxk];

inline int fr(int u)
{
    if(fa[u]==u) return u;
    return fa[u]=fr(fa[u]);
}
inline void init_kls()
{
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(edge+1,edge+m+1);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int u=edge[i].se.fi,v=edge[i].se.se,w=edge[i].fi;
        int fu=fr(u),fv=fr(v);
        if(fu==fv) continue;
        fa[fu]=fv;
        ans+=w;
        UE[++cnt]=edge[i];
        if(cnt==n-1) break;
    }
}
inline ll kls()
{
    for(int i=1;i<=n+k;i++) fa[i]=i;
    ll sum=0;int cnt=0;
    for(int i=1;i<=cntad;i++)
    {
        if(cis[ad[i].se.fi-n])
            tmp1[++cnt]=ad[i];
    }
    for(int i=1,j=1;i<n&&j<=cnt;)
    {
        pair<int,pii>now;
        if(UE[i].fi<tmp1[j].fi) now=UE[i],i++;
        else now=tmp1[j],j++;

        int u=now.se.fi,v=now.se.se,w=now.fi;
        int fu=fr(u),fv=fr(v);
        if(fu==fv) continue;
        fa[fu]=fv;
        sum+=w;
    }
    // cerr<<sum<<"\n";
    return sum;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge[i]={w,{u,v}};
    }
    init_kls();
    for(int i=1;i<=k;i++)
    {
        int id=n+i;
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)
        {
            int w;
            scanf("%d",&w);
            ad[++cntad]={w,{id,j}};
        }
    }
    sort(ad+1,ad+cntad+1);
    for(int i=1;i<(1<<k);i++)
    {
        ll sum=0;
        // cerr<<i<<":";
        for(int j=0;j<k;j++)
        {
            cis[j+1]=0;
            if((i>>j)&1)
            {
                // cerr<<j+1<<" ";
                cis[j+1]=1,sum+=c[j+1];
            }
        }
        // cerr<<":"<<sum<<" ";
        ans=min(ans,kls()+sum);
    }
    printf("%lld\n",ans);
}