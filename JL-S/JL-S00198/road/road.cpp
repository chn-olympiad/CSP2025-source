#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int k;
int u[100005];
int v[100005];
int w[100005];
int a[100005][106];
int c[100005];
struct node
{
    int v,dis;
};
vector <node> mp[100005];
int vis[100005];
int ans=1e9;
void dfs(int s,int sum)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=1)
        {
            break;
        }
        cnt++;
    }
    if(cnt==n)
    {
        ans=min(ans,sum);
    }

    for(int i=0;i<mp[s].size();i++)
    {
        int v=mp[s][i].v;
        int w=mp[s][i].dis;
        vis[s]=1;
        vis[v]=1;
        dfs(v,sum+w);
        vis[v]=0;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        mp[u[i]].push_back({v[i],w[i]});
    }
    dfs(1,w[1]);
    cout<<ans;

}
