#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    long long u,v,w;
    bool operator >(const Edge & o)const
    {
        return w>o.w;
    }
};
priority_queue<Edge,vector<Edge>,greater<Edge>>q;
long long n,m,k,c[15],a[15][10005],ans,uu,vv,ww,f[10005];
int find(int x)
{
    if(f[x]==x)
    {
        return x;
    }
    return f[x]=find(f[x]);
}
void move(int x,int y)
{
    f[find(x)] = find(y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        f[i] = i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>uu>>vv>>ww;
        q.push({uu,vv,ww});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        ans += c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    while(q.size())
    {
        Edge f=q.top();
        q.pop();
        if(find(f.u)!=find(f.v))
        {
            ans += f.w;
            move(f.u,f.v);
        }
    }
    cout<<ans<<endl;
    return 0;
}