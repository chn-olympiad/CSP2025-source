#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[200006],ans;
struct node{
    int x,y,z;
}a[2000006];
bool cmp(node q,node w)
{
    return q.z<w.z;
}
int fd(int l)
{
    if(fa[l]==l)
    {
        return l;
    }
    fa[l]=fd(fa[l]);
    return fa[l];
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        a[i].x=x;
        a[i].y=y;
        a[i].z=z;
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(fd(a[i].x)!=fd(a[i].y))
        {
            fa[fa[a[i].x]]=fa[a[i].y];
            ans+=a[i].z;
        }
    }
    for(int i=1;i<=k;i++)
    {
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
    }
    cout<<ans;
    return 0;
}
