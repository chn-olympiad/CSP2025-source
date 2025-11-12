#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
struct edge
{
    int u,v,w;
    bool operator < (const edge &x)const
    {
        return w<x.w;
    }
}e[1000006];
int pa[20004];
int c[20],a[20][10004];
int get_fa(int x)
{
    return pa[x]==x?x:pa[x]=get_fa(pa[x]);
}
vector<edge> eds,es;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        pa[i]=i;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    sort(e+1,e+m+1);
    ll res=0,ans=1e18;
    for(int i=1;i<=m;i++)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int uu=get_fa(u),vv=get_fa(v);
        if(uu!=vv)
        {
            pa[uu]=vv;
            res+=w;
            eds.push_back({u,v,w});
        }
    }
    // for(int i=0;i<n-1;i++)
    //     cout<<eds[i].u<<" "<<eds[i].v<<" "<<eds[i].w<<"\n";
    ans=min(ans,res);
    for(int s=1;s<(1<<k);s++)
    {
        res=0;
        es.clear();
        for(auto i:eds) es.push_back(i);
        for(int i=1;i<=k;i++)
        {
            if(s&(1<<(i-1)))
            {
                for(int j=1;j<=n;j++)
                    es.push_back({i+n,j,a[i][j]});
                res+=c[i];
            }
        }
        for(int i=1;i<=n+k;i++)
            pa[i]=i;
        sort(es.begin(),es.end());
        for(int i=0;i<(int)es.size();i++)
        {
            int u=es[i].u,v=es[i].v,w=es[i].w;
            int uu=get_fa(u),vv=get_fa(v);
            if(uu!=vv)
            {
                pa[uu]=vv;
                res+=w;
            }
        }
        ans=min(res,ans);
    }
    cout<<ans<<"\n";
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
/*
4 7 1
2 1 8
3 2 3
4 2 10
4 4 4
2 3 2
4 1 8
3 3 4
8 2 1 10 8 
*/