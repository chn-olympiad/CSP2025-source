#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;


vector<pair<int,pair<int,int>>>e;
int fa[N],c[15];
int n,m,k;


int _find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=_find(fa[x]);
}

int kruskar(int num,int sum)
{
    for(int i=1;i<=n+k;i++)
        fa[i]=i;

    int ans=0,cnt=0;
    for(auto [w,x]:e)
    {
        auto [u,v]=x;
        if(1<<u-n-1&num||u<=n)
        {
            int fu=_find(u),fv=_find(v);
            if(fu!=fv)
            {
                fa[fu]=fv;
                ans+=w;
                cnt++;
            }
            if(cnt==sum) break;
        }
    }
    return ans;
}

int kruskar_114(int num)
{
    for(int i=1;i<=n+k;i++)
        fa[i]=i;

    int ans=0;
    for(auto [w,x]:e)
    {
        auto [u,v]=x;
        int fu=_find(u),fv=_find(v);
        if(fu!=fv)
        {
            fa[fu]=fv;
            ans+=w;
        }
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int u,v,w;
    cin>>n>>m>>k;
    bool flag=1;
    while(m--)
    {
        cin>>u>>v>>w;
        e.push_back({w,{u,v}});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i],flag&=!c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>w;
            e.push_back({w,{n+i,j}});
        }
    }
    sort(e.begin(),e.end());

    if(flag)
    {
        cout<<kruskar_114(0)<<'\n';
        exit(0);
    }

    int ans=kruskar(0,n);
    for(int i=1;i<1<<k;i++)
    {
        int num=0,sum=0;
        for(int j=1;j<=k;j++)
            if(1<<j-1&i) num+=c[j],sum++;
        ans=min(ans,kruskar(i,n+sum)+num);
    }

    cout<<ans<<'\n';
    return 0;
}
