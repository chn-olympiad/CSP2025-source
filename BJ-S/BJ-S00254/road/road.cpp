#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[25],ans=1e18;
int fa[200010];
struct node
{
    long long u,v,w;
}e[2000010];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int Find(int u)
{
    if(fa[u]==u) return u;
    else return fa[u]=Find(fa[u]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;++i)
    {
        cin>>c[i];
        long long w;
        for(int j=1;j<=n;++j)
        {
            cin>>w;
            m++;
            e[m].u=n+i;e[m].v=j;e[m].w=w;
        }
    }
    sort(e+1,e+m+1,cmp);
    for(int p=0;p<=(1<<k)-1;++p)
    {
        long long cnt=0,t=0,is=n;
        for(int i=1;i<=k;++i)
        {
            if(p&(1<<(i-1)))
            {
                is++;
                cnt+=c[i];
            }
        }
        if(cnt>ans) continue;
        for(int i=1;i<=n+k;++i) fa[i]=i;
        for(int i=1;i<=m;++i)
        {
            long long u=e[i].u,v=e[i].v,w=e[i].w;
            if(u>n)
            {
                if((p&(1<<(u-n-1)))==0)
                continue;
            }
            if(Find(u)!=Find(v))
            {
                fa[Find(u)]=fa[Find(v)];
                cnt+=w;
                t++;
            }
            if(cnt>ans) break;
            if(t==is-1) break;
        }
        if(t==is-1)
        {
            ans=min(ans,cnt);
        }
    }
    cout<<ans<<endl;
    return 0;
}
