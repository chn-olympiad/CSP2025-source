#include<bits/stdc++.h>
using namespace std;
const int N=1e4+30,M=2e6+10;
struct EDGE
{
    int x,y,w;
    bool operator <(const EDGE& m) const
    {
        return w<m.w;
    }
}edge[M],edge1[M];
int n,m,k,dis[15][N],w[15],f[N];
long long sum=1e18;
bool t[15];
int read()
{
    int sum=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        sum=(sum<<3)+(sum<<1)+(c^48),c=getchar();
    return sum*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    int a[20],cnt=0;
    while(x)
        a[++cnt]=x%10,x/=10;
    while(cnt)
        putchar(a[cnt--]+'0');
}
int find(int x)
{
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
void check()
{
    for(int i=1;i<=m;i++)
        edge[i]=edge1[i];
    int cnt=m,num=0;
    long long ans=0;
    for(int i=1;i<=k;i++)
        if(t[i])
        {
            num++;
            ans+=1ll*w[i];
            for(int j=1;j<=n;j++)
                edge[++cnt]=EDGE{n+num,j,dis[i][j]};
        }
    num+=n;
    for(int i=1;i<=num;i++)
        f[i]=i;
    sort(edge+1,edge+cnt+1);
    for(int i=1;i<=cnt;i++)
    {
        int x=edge[i].x,y=edge[i].y,w=edge[i].w;
        x=find(x),y=find(y);
        if(x==y) continue;
        ans+=1ll*w;
        num--;
        if(num==1) break;
        f[x]=y;
    }
    if(num==1)
        sum=min(sum,ans);
}
void dfs(int j)
{

    if(j>=k+1)
    {
        check();
        return;
    }
    t[j]=1;
    dfs(j+1);
    t[j]=0;
    dfs(j+1);
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    bool fl=1;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        x=read();y=read();z=read();
        edge1[i]=edge[i]=EDGE{x,y,z};
    }
    for(int i=1;i<=k;i++)
    {
        w[i]=read();
        if(w[i]!=0) fl=0;
        for(int j=1;j<=n;j++)
            dis[i][j]=read();
    }
    if(fl==1)
    {
        for(int i=1;i<=k;i++)
            t[i]=1;
        check();
        write(sum);
        return 0;
    }
    dfs(1);
    write(sum);
    return 0;
}
