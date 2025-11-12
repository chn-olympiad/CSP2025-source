#include <bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+5;
int f[N];
int find(int x)
{
    if(f[x]==x) return x;
    return (f[x]=find(f[x]));
}
void merge(int x,int y)
{
    if(find(x)!=find(y))
    {
        f[f[x]]=f[y];
    }
}
struct edge
{
    int u,v,w;
    bool operator<(const edge b)const
    {
        return w>b.w;
    }
};
priority_queue<edge>pq;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        pq.push({u,v,w});
    }
    if(k==0)
    {
        long long ans=0;
        while(!pq.empty())
        {
            edge abc=pq.top();
            int u=abc.u,v=abc.v,w=abc.w;
            pq.pop();
            if(find(u)!=find(v))
            {
                merge(u,v);
                ans+=w;
            }
        }
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}