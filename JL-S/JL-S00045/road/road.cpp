#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int u,v,w;
};
node a[2000005];
int pa[10005],c[15];
int get_fa(int x)
{
    if(pa[x]==x)
        return x;
    return pa[x]=get_fa(pa[x]);
}
int n,m,k;
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int sqqrt(int cnt)
{
    int ans=0;
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        int u=a[i].u,v=a[i].v,w=a[i].w;
        int uu=get_fa(u),vv=get_fa(v);
        //cout<<uu<<" "<<vv<<endl;
        if(uu!=vv)
        {
            ans+=w;
            pa[uu]=vv;
            //cout<<u<<" "<<v<<endl;
            //cout<<endl;
        }
    }
    return ans;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++)
        pa[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    int cnt=m,flag=0;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]!=0)
            flag=1;
        for(int j=1;j<=n;j++)
        {
            cnt++;
            cin>>a[cnt].w;
            a[cnt].u=n+i;
            a[cnt].v=j;
        }
    }
    cout<<sqqrt(cnt);
}
