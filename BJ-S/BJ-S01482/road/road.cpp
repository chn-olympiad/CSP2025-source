#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,w;
    bool operator<(const node& other) const{
        return w<other.w;
    }
};
vector<int> p;
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
bool unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return false;
    p[y]=x;
    return true;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    vector<node> e;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,w});
    }
    for(int j=1;j<=k;j++)
    {
        int c;
        cin>>c;
        e.push_back({0,n+j,c});
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            e.push_back({n+j,i,a});
        }
    }
    int to=n+k+1;
    p.resize(to);
    for(int i=0;i<to;i++) p[i]=i;
    sort(e.begin(),e.end());
    long long t=0;
    int cnt=to;
    for(const node& z : e)
    {
        if(unite(z.u,z.v))
        {
            t+=z.w;
            cnt--;
            if(cnt==1) break;
        }
    }
    cout<<t;
    return 0;
}