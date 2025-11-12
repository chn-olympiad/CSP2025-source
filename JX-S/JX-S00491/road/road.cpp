#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
vector<pair<int,long long>> va[1000001];
long long ans=0;
bool vis[1000001];
int n,m,k;
void dfs(int s)
{
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        pair<long long,int> tp=q.top();
        q.pop();
        if(vis[tp.second]==true)
        {
            continue;
        }
        vis[tp.second]=true;
        ans+=tp.first;
        for(auto v:va[tp.second])
        {
            q.push(make_pair(v.second,v.first));
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        long long r;
        cin>>u>>v>>r;
        va[u].push_back(make_pair(v,r));
        va[v].push_back(make_pair(u,r));
    }
    for(int i=1;i<=k;i++)
    {
        long long temp;
        for(int i=0;i<=n;i++)
        {
            cin>>temp;
        }
    }
    dfs(1);
    cout<<ans;
    return 0;
}
