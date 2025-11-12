#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+20;
vector<pair<int,int>> g[N];
int c[20][N],cst[20];
int vis[N];
int n,m,k;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
ll prim(int x)
{
    while(!q.empty()) q.pop();
    memset(vis,0,sizeof vis);
    q.push({0,1});
    pair<int,int> t;
    int to,w,now,cnt=0;
    ll ans=0;
    while(!q.empty())
    {
        t=q.top();
        q.pop();
        if(vis[t.second]) continue;
        //cout<<t.first<<" "<<t.second<<endl;
        now=t.second;
        vis[now]=1;
        ans+=t.first;
        cnt++;
        //cout<<cnt<<endl;
        if(cnt==x) break;
        for(auto i:g[now])
        {
            if(!vis[i.second])
            {
                q.push({i.first,i.second});
            }
        }
    }
    return ans;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    int f=1;
    for(int i=1;i<=k;i++)
    {
        cin>>cst[i];
        if(cst[i]!=0) f=0;
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
            g[i+n].push_back({c[i][j],j});
        }
    }
    if(f==1)
    {
        for(int j=1;j<=k;j++)
        {
            for(int k=1;k<=n;k++)
            {
                g[k].push_back({c[j][k],j+n});
            }
        }
        cout<<prim(n+k);
        return 0;
    }
    ll ans=(1ll<<60),t,sum=0;
    int cnt=0;
    for(int i=0;i<(1<<k);i++)
    {
        cnt=sum=0;
        for(int j=1;j<=k;j++)
        {
            if((i>>(j-1))&1)
            {
                cnt++;
                sum+=cst[j];
                for(int k=1;k<=n;k++)
                {
                    g[k].push_back({c[j][k],j+n});
                }
            }

        }
        t=prim(n+cnt);
        //cout<<i<<" "<<t+sum<<endl<<endl;
        ans=min(ans,t+sum);
        for(int j=1;j<=cnt;j++)
        {
            for(int k=1;k<=n;k++)
            {
                g[k].pop_back();
            }
        }
    }
    cout<<ans;
}
