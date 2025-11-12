#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int u,v,w;
};
int n,m,k,f[100010],c[100010],h[100010],b[20][1000010],cnt;
long long ans;
node a[5000010];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int find(int x)
{
    return x==f[x]?x:f[x]=find(f[x]);
}
inline int read()
{
    int s=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while('0'<=c&&c<='9')
        s=s*10+c-'0',c=getchar();
    return s;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
        a[i].u=read(),a[i].v=read(),a[i].w=read();
    cnt=m;
    for(int i=1;i<=k;i++)
    {
        c[i]=read();
        for(int j=1;j<=n;j++)
            b[i][j]=read(),h[i]=(b[i][j]?h[i]:j);
        if(h[i]&&c[i]==0)
            for(int j=1;j<=n;j++)
                if(j!=h[i])
                    a[++cnt].u=h[i],a[cnt].v=j,a[cnt].w=b[i][j];
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
    {
        if(find(a[i].u)!=find(a[i].v))
            ans+=a[i].w,f[find(a[i].v)]=find(a[i].u);
    }
    cout<<ans;
    return 0;
}
