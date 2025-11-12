#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,w;
}a[1000005];
int f[1000005],k,m,n;
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int find(int x)
{
    if (f[x]==x)
    {
        return x;
    }
    else
    {
        f[x]=find(f[x]);
        return f[x];
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    if (k!=0)
    {
        cout<<"0";
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for (int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+m+1,cmp);
    long long ans=0;
    for (int i=1;i<=m;i++)
    {
        int x=find(a[i].u),y=find(a[i].v);
        if (x!=y)
        {
            f[x]=y;
            ans+=a[i].w;
        }
    }
    cout<<ans;
    return 0;
}