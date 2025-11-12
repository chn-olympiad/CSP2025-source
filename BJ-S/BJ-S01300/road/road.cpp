#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int x,y;
    long long d;
}a[2000010];
bool cmp(node x,node y)
{
    return x.d<y.d;
}
int fa[20010],n,m,k;
long long tem[20010],ans;
int find(int x)
{
    if(fa[x]==x)    return x;
    return fa[x]=find(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].d);
    }
    int cnt=m;
    for(int i=1;i<=k;i++)
    {
        int t;
        scanf("%d",&t);
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&tem[j]);
            if(tem[j]==0)   t=j;
        }
        for(int j=1;j<=n;j++)
        {
            if(j==t)    continue;
            cnt++;
            a[cnt].d=tem[j];
            a[cnt].x=j;
            a[cnt].y=t;
        }
    }
    sort(a+1,a+cnt+1,cmp);
    /*for(int i=1;i<=cnt;i++)
    {
        cout << a[i].x << " " << a[i].y << " " << a[i].d << endl;
    }*/
    for(int i=1;i<=cnt;i++)
    {
        int x=a[i].x,y=a[i].y;
        if(find(x)==find(y))    continue;
        fa[find(x)]=find(y);
        ans+=a[i].d;
    }
    printf("%lld\n",ans);
    return 0;
}
