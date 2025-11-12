#include<bits/stdc++.h>
using namespace std;
#define int    long long
int n,m,k;
struct edge
{
    int u,v,w;
}e[1000005];
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
int fa[10005];
int c[15],a[15][10005];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
vector<edge>ok;
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    int now=n-1;
    int sum1=0;
    for(int i=1;i<=m;i++)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(find(u)==find(v))continue;
        fa[find(u)]=find(v);
        ok.push_back(e[i]);
        now--;
        sum1+=w;
        if(now<=0)break;
    }
    int ans=sum1;
    for(int t=0;t<(1<<k);t++)
    {
        int sum2=0;
        
//        cout<<"< < < < < < < < CURRENTLY EXAMINING ON ";
//        int tmp=t;
//        for(int i=0;i<k;i++)if((tmp&(1<<i)))cout<<i+1<<" ";
//        cout<<"> > > > > > > >"<<endl;
        vector<edge>ok2=ok;
        for(int i=1;i<=k;i++)
        {
            if((t&(1<<(i-1))))
            {
//                cout<<"------------- < PROCESSING ON "<<i<<" > -------------"<<endl;
                sum2+=c[i];
//                cout<<"sum2 added c[i] = "<<c[i]<<" to "<<sum2<<endl;
                bool vis[10005];
                memset(vis,0,sizeof(vis));
                for(int j=0;j<(int)ok2.size();j++)
                {
                    int u=ok[j].u,v=ok[j].v,w=ok[j].w;
                    int tmp=0;
                    if(!vis[u])tmp+=a[i][u];
                    if(!vis[v])tmp+=a[i][v];
//                    cout<<"possible swap in "<<u<<" and "<<v<<" with cost "<<tmp<<endl;
//                    cout<<"(original cost: "<<w<<")"<<endl;
                    if(a[i][u]+a[i][v]<w)
                    {
                        sum2-=w;
                        sum2+=tmp;
                        vis[u]=vis[v]=1;
                        ok2[j].w=tmp;
//                        cout<<"bought swap, sum2 = "<<sum2<<endl;
                    }
                }
            }
        }
//        cout<<sum2<<endl;
        ans=min(ans,sum1+sum2);
    }
//    cout<<sum1<<endl;
    cout<<ans<<endl;
}

/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13

*/
