#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[1005],ans;
struct Edge
{
    long long a,b,w;
};
long long find(long long x)
{
    if(f[x]==x)return x;
    else
    {
        f[x]=find(f[x]);
        return f[x];
    }
}
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
Edge edge[1000006];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(long long i=1;i<=n;i++)f[i]=i;
    for(long long i=1;i<=m;i++)
    {
        cin>>edge[i].a>>edge[i].b>>edge[i].w;
    }
    sort(edge+1,edge+m+1,cmp);
    for(long long i=1;i<=m;i++)
    {
        long long a=edge[i].a,b=edge[i].b,w=edge[i].w;
        long long fa=find(a),fb=find(b);
        if(fa!=fb)
        {
            ans+=w;
            f[fa]=fb;
        }
    }
    cout<<ans;
    return 0;
}
