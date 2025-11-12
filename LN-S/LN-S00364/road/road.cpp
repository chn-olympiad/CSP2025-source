#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int k,c[maxn],n,f[maxn],m,mem;
struct edge
{

    int u;int v;int w;
}a[maxn];
int findd(int x)
{
     if(x==f[x])
        return x;
     else
     {
         f[x]=findd(f[x]);
         return f[x];
     }
}
void unionn(int x,int y)
{
    int x_f=findd(x);
    int y_f=findd(y);
    if(x_f!=y_f)
        f[x_f]=y_f;
}
bool cmp(edge x,edge y)
{

    return x.w<y.w;
}
int pd()
{

    for(int i=1;i<=n;i++)
        {

            if(findd(i)!=findd(1))
            {
                return 0;
                mem=i;
            }
        }
        return 1;
}
int main()
{
    freopen("road1.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int ui,vi,wi;
        cin>>ui>>vi>>wi;
        a[i].u=ui;
        a[i].v=vi;
        a[i].w=wi;
    }
    int cnt=m;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            int wi;
            cin>>wi;
            cnt++;
            int vi=i+n;
            a[cnt].u=j;
            a[cnt].v=vi;
            a[cnt].w=wi+c[i];
        }
    }
    sort(a+1,a+1+cnt,cmp);
    int ans=0;
    for(int i=1;i<=cnt;i++)
    {
        if(findd(a[i].u)!=findd(a[i].v)&&(a[i].u<=n&&a[i].v<=n))
        {
            unionn(a[i].u,a[i].v);
            ans+=a[i].w;
        }
        if(pd())
            break;
    }
    cout<<ans;
    return 0;
}
