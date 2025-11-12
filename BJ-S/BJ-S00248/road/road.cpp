#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;
long long c[15],a[15][N],n,m,k,ans[N],r[N],cnt1,cnt;
struct node{
    int v,w;
};
bool check(int x,int r[])
{
    bool flag=false;
    for(int i=1;i<=cnt;i++)
    {
        if(r[i]==x) flag=true;
    }
    return flag;
}
vector<node> e[N];
priority_queue<int, vector < int > , greater < int > > q;
void dfs(int u,int re)
{
    r[cnt1++]=u;
    if(cnt1==n)
    {
        ans[cnt++]=re;
        cnt1=0;
        return ;
    }
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i].v , w=e[u][i].w;
        if(!check(v,r))
        {
            dfs(v,re+w);
        }
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int j=1;j<=k;j++)
    {
        cin>>c[j];
        for(int i=1;i<=n;i++)
        {
            cin>>a[j][i];
        }
    }
    dfs(1,0);
    long long ans1=1<<30;
    for(int i=1;i<=cnt;i++)
    {
        ans1=min(ans1,ans[i]);
    }
    cout<<ans1<<endl;
    return 0;
}
/*
祝我3+0.5能考上！初三上期中考试顺利！初三上12月月考顺利！
语文顺利！
数学顺利！
英语顺利！
道法顺利！
物理顺利！
化学顺利！
历史顺利！
*/
