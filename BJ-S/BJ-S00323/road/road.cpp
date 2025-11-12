#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[20005],vis[20005],n,m,k;
priority_queue<pair<int,pair<int,int> > > q;
int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
void merge(int x,int y)
{
    x=find(x);y=find(y);
    if(x!=y)f[x]=y;
}
ll kru()
{
    ll res=0,b=0;
    while(q.size())
    {
        int u=q.top().second.first,v=q.top().second.second,w=-q.top().first;q.pop();
        if(find(u)==find(v)||(u>m&&find(0)!=find(u))||b==n)continue;
        res+=w;
        //cout<<'('<<u<<','<<v<<")\n";
        merge(u,v);
    }
    return res;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k+1;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        q.push({-w,{u,v}});
    }
    for(int i=1;i<=k;i++)
    {
        int mo;
        cin>>mo;
        //q.push({-mo,{0,1+m+i}});
        for(int j=1,x;j<=n;j++)
        {
            cin>>x;
            //q.push({-x,{1+m+i,j}});
        }
    }
    cout<<kru()<<'\n';
    return 0;
}
//4 4 2 2 1 4 6 3 2 3 7 4 4 2 5 5 4 3 4 6 1 1 8 2 4 100 1 3 2 4

