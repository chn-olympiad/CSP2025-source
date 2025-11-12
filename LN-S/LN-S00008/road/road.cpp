#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
    int u,v,len;
}a[1000010];
int city[10010];
int fa[10010];
bool cmp(node n1,node n2)
{
    return n1.len<n2.len;
}
int find(int x)
{
    if(fa[x]==x)
    {
        return x;
    }
    else return fa[x]=find(fa[x]);
}
bool merge(int u,int v)
{
    int tx=find(u);
    int ty=find(v);
    if(tx!=ty)
    {
        fa[v]=u;
        return 1;
    }
    return 0;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].len;
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    long long ans=0;
    int sum=0;
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(merge(a[i].u,a[i].v))
        {
            ans+=a[i].len;
            sum++;
            if(sum+1==n)break;
        }
    }
    cout<<ans;
    return 0;
}
