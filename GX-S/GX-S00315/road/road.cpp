#include<bits/stdc++.h>
#define N 1001
#define M 1000001
using namespace std;
long long read()
{
  long long x=0,f=1;char c=getchar();
  while(!isdigit(c))
  {
      if(c=='-') f=-1;
      c=getchar();
  }
  while(isdigit(c))
  {
      x=x*10+c-'0';
      c=getchar();
  }
  return x*f;
}
int n,m,k,rd[N];
long long f[N][N];
long long minn(long long x,long long y)
{
    return x<y ? x:y;
}
struct nx
{
  long long x,y,w;
}a[M];
long long b[N],cnt;
bool gz(nx a1,nx a2)
{
  return a1.w>a2.w;
}
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    memset(f,0x7f7f7f7f,sizeof(f));
    for(int i=1;i<=n;i++) rd[i]=n-1;
    for(int i=1;i<=m;i++)
    {
      long long u=read(),v=read(),w=read();
      f[u][v]=f[v][u]=w;
    }
    for(int i=1;i<=k;i++)
    {
      int c=read();
      for(int j=1;j<=n;j++)  b[j]=read();
      for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
          if(x!=y)
            f[x][y]=minn(f[x][y],b[x]+b[y]);
          else
            f[x][y]=0;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            a[++cnt].x=i,a[cnt].y=j,a[cnt].w=f[i][j];
    sort(a+1,a+n+1,gz);
    for(int i=1;i<=cnt;i++)  if(rd[a[i].x]-1>=1&&rd[a[i].y]-1>=1) f[a[i].x][a[i].y]=0,rd[a[i].x]--,rd[a[i].y]--;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ans+=f[i][j];
    printf("%lld",ans);
    return 0;
}
