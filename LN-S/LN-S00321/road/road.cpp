#include<cstdio>
#include<algorithm>
using namespace std;
#define N 10005
#define M 2000005
int fa[N],ans,to[M],nxt[M],he[N],va[M],tot,v[M],l[M],r[M];
int fd(int x)
{if(fa[x]==x)return x;
return fa[x]=fd(fa[x]);}
struct node{
    int l,r,v;
}a[M];
void bu(int x,int y,int w)
{
    to[++tot]=y;
    nxt[tot]=he[x];
    va[tot]=w;
    he[x]=tot;
}bool cmp(node a,node b)
{
    return a.v<b.v;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        bu(x,y,w);
        bu(y,x,w);
        v[i]=w;
        l[i]=x;
        r[i]=y;
    }if(k==0)
    {
        int ans=0;
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;i++)
        {
            int ll=fd(a[i].l),rr=fd(a[i].r);
            if(ll==rr)continue;
            fa[a[i].l]=fa[a[i].r];
            ans+=a[i].v;
        }printf("%d",ans);
        return 0;
    }
    //for()
    return 0;
}