#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
    int v;
    ll w;
};
vector<node> g[10005];
int c[15],a[15][10005],f[10005],v[10005];
int getfa(int ret)
{
    if(f[ret]==ret)
    {
        return ret;
    }
    else
    {
        f[ret]=getfa(f[ret]);
    }
    return f[ret];
}
void add(int ret,int fa)
{
    if(getfa(ret)==getfa(fa))
    {
        return ;
    }
    f[getfa(ret)]=getfa(fa);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        node st;
        st.v=v;
        st.w=w;
        g[u].push_back(st);
        st.v=u;
        g[v].push_back(st);
    }
    bool flag=true;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        if(c[i]!=0)
        {
            flag=false;
        }
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0)
            {
                flag=false;
            }
        }
    }
    if(flag==true)
    {
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                continue;
            }
            ll minn=1e18;
            for(int kk=1;kk<=k;kk++)
            {
                minn=min(minn,c[kk]*1ll+a[kk][i]*1ll+a[kk][j]*1ll);
            }
            node st;
            st.v=j;
            st.w=minn;
            g[i].push_back(st);
            st.v=i;
            g[j].push_back(st);
        }
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    int id=0;
    v[++id]=1;
    ll ans=0;
    for(int i=2;i<=n;i++)
    {
        ll minn=1e18;
        int mini;
        for(int j=1;j<=id;j++)
        {
            for(auto vv:g[v[j]])
            {
                if(getfa(vv.v)==getfa(v[j]))
                {
                    continue;
                }
                if(minn>vv.w)
                {
                    minn=vv.w;
                    mini=vv.v;
                }
            }
        }
        ans+=minn;
        add(mini,v[1]);
        v[++id]=mini;
    }
    printf("%lld\n",ans);
    // cerr<<(clock()*1.0)/CLOCKS_PER_SEC<<"s\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}