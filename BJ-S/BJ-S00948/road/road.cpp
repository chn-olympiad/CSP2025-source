#include <bits/stdc++.h>
using namespace std;
int n, m, k, c, a[1000005], f[100005], sum, v[1000005];
vector<pair<int, int>> e[100005];
priority_queue<pair<int,int>> p;
int find(int x)
{
    if(f[x]!=x) return f[x]=find(f[x]);
    return f[x];
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        e[u].push_back({w, v});
        e[v].push_back({w, u});
    }
    for(int i=1;i<=n;i++) f[i]=i;
    p.push({0, 1});
    v[1]=1;
    if(k==0)
    {
        while(!p.empty())
        {
            auto [w, u]=p.top();
            int u1=0, w1=1e9;
            v[u]=1;
            p.pop();
            for(auto [uu, vv]:e[u])
            {
                if(find(vv)!=find(u) && w1>uu)
                {
                    w1=uu, u1=vv;
                }
                if(find(vv)!=find(u)) p.push({uu, vv});
            }
            v[u1]=1;
            if(w1!=1e9)
            sum+=w1;
            f[u]=find(u1);
            if(u1)
            p.push({w1, u1});
        }
    }
    cout<<sum;
    return 0;
}
