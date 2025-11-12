#include<bits/stdc++.h>
using namespace std;
int fa[100005];
int n,m,k,t,ans;
struct abc
{
    int a,b,z;
}a[100005];
bool cmp(abc x,abc y)
{
    return x.z<y.z;
}
int find(int x)
{
    if(fa[x]==x)
    {
        return x;
    }
    return fa[x]=find(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].z;
        }
        for(int i=1;i<=k;i++)
        {
            int x;
            cin>>x;
        }
        for(int i=1;i<=m;i++)
        {
            fa[i]=i;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            int u=find(a[i].a),v=find(a[i].b);
            if(u==v)
            {
                continue;
            }
            fa[u]=v;
            ans+=a[i].z;
        }
        cout<<ans<<"\n";
    }

    return 0;
}
