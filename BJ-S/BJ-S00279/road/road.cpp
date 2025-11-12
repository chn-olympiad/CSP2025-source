#include<bits/stdc++.h>
#define endl '\n'
#define fis first
#define sec second
using namespace std;
typedef long long ll;
const ll inf=1e18;
ll n,m,k,sum[1050],ans=inf,cnt,end_vis;
ll c[15][10005],mc[15];
ll nc[1050][10005];
ll fa[10005];
bool vis[15],r_v[15];
struct node
{
    ll u,v,w;
    bool friend operator < (node x,node y)
    {
        return x.w<y.w;
    }
}a[1000005];
ll find(ll x)
{
    if(x==fa[x])return x;
    return find(fa[x]);
}
vector<pair<ll,ll> > G[10005];
void dfs(ll x,ll f,ll w,ll id)
{
    ll minc=inf,minrc=inf;
    vector<ll> mini;
    for(int i=0;i<k;i++)
    {
        if(vis[i+1])
        {
            //cout<<"v:"<<i+1<<" "<<c[i+1][x]<<endl;
            minc=min(minc,c[i+1][x]);
        }
        if(r_v[i+1])
        {
            //cout<<f<<endl;
            if(minrc>c[i+1][f]+c[i+1][x]&&f)
            {
                minrc=min(minc,c[i+1][f]+c[i+1][x]);
                mini.push_back(i+1);
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(r_v[i])
        {
            if(c[i][mc[i]]==c[i][x])
            {
                vis[i]=1;
                r_v[i]=0;
                sum[id]+=c[i][mc[i]];
                //cout<<i<<" "<<c[i][mc[i]]<<" "<<id<<endl;
                for(auto mi:mini)
                {
                    if(mi==i)
                    {
                        minrc-=c[i][mc[i]];
                        break;
                    }
                }
            }
        }
    }
    //cout<<minc<<" "<<minrc<<" "<<id<<endl;
    minc=min(minc,minrc);
    if(minc<w)sum[id]=sum[id]-w+minc;
    for(auto y:G[x])
    {
        if(y.fis!=f)dfs(y.fis,x,y.sec,id);
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(nc,0x3f,sizeof(nc));
    //memset(mc,0x3f,sizeof(mc));
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        mc[i]=1;
        cin>>c[i][0];
        for(int j=1;j<=n;j++)
        {
            //cout<<j<<endl;
            cin>>c[i][j];
            if(c[i][mc[i]]>c[i][j])
            {
                mc[i]=j;
            }
        }
        //cout<<"114514"<<endl;
    }
    //cout<<"1919810"<<endl;
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++)
    {
        ll fu=find(a[i].u),fv=find(a[i].v);
        if(fu!=fv)
        {
            fa[fu]=fv;
            sum[0]+=a[i].w;
            G[a[i].u].push_back({a[i].v,a[i].w});
            G[a[i].v].push_back({a[i].u,a[i].w});
            if(++cnt==n-1)break;
        }
    }
    ans=min(ans,sum[0]);
    //cout<<sum[0]<<endl;
    for(int i=1;i<(1<<k);i++)
    {
        memset(vis,0,sizeof(vis));
        memset(r_v,0,sizeof(r_v));
        sum[i]=sum[0];
        for(int j=0;j<k;j++)
        {
            if(i&(1<<j))
            {
                end_vis=j+1;
        //        vis[mc[j+1]]=1;
                r_v[j+1]=1;
                sum[i]+=c[j+1][0];
        //        for(int l=1;l<=n;l++)
        //        {
        //            nc[i][l]=min(nc[i][l],c[j+1][l]);
        //        }
            }
        }
        //for(int l=1;l<=n;l++)
        //{
        //    cout<<nc[i][l]<<" ";
        //}
        //cout<<endl;
        //sum[i]-=c[end_vis][mc[end_vis]];
        //cout<<sum[i]<<endl;
        //vis[end_vis]=1;
        //r_v[end_vis]=1;
        //cout<<mc[end_vis]<<endl;
        dfs(mc[end_vis],0,0,i);
        ans=min(ans,sum[i]);
        //cout<<sum[i]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
