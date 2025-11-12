#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline void in(T &x){
    char ch=getchar();
    int f=1;x=0;
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
    return;
}
int n,m,k,fa[10005],len,c[15][10005],dis[10005],tot;
ll sum,ans,now;
struct node
{
    int x,y,w;
}a[1000005],t[1000005],b[1000005];
inline bool cmp(node p,node q)
{
    return p.w<q.w;
}
inline int find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
inline void kru()
{
    int tmp=n;
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=m;++i)
    {
        int x=find(a[i].x),y=find(a[i].y);
        if(x!=y)
        {
            t[++len]=a[i];
            fa[y]=x;
            sum+=a[i].w;
            if(--tmp==1) break;
        }
    }
    return;
}
inline void Kru()
{
    int tmp=n+k;
    for(int i=1;i<=n+k;++i) fa[i]=i;
    for(int i=1;i<=tot;++i)
    {
        int x=find(b[i].x),y=find(b[i].y);
        if(x!=y)
        {
            fa[y]=x;
            now+=b[i].w;
            if(--tmp==1||now>=ans) break;
        }
    }
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    in(n),in(m),in(k);
    for(int i=1;i<=m;++i)
    {
        in(a[i].x),in(a[i].y),in(a[i].w);
    }
    for(int i=1;i<=k;++i)
    {
        for(int j=0;j<=n;++j)
        {
            in(c[i][j]);
        }
    }
    sort(a+1,a+1+m,cmp);
    kru();
    ans=sum;
    for(int i=1;i<(1<<k);++i)
    {
        now=tot=0;
        for(int l=1;l<=n;++l) dis[l]=1e9;
        for(int j=1;j<=k;++j)
        {
            if((1<<j-1)&i)
            {
                now+=c[j][0];
                for(int l=1;l<=n;++l)
                {
                    b[++tot].x=l;
                    b[tot].y=n+j;
                    b[tot].w=c[j][l];
                }
            }
            else
            {
                b[++tot].x=1;
                b[tot].y=n+j;
                b[tot].w=0;
            }
        }
        for(int j=1;j<=len;++j) b[++tot]=t[j];
        sort(b+1,b+1+tot,cmp);
        Kru();
        ans=min(ans,now);
    }
    printf("%lld\n",ans);
    return 0;
}
