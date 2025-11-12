#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=1005;
int n,m,k,t=0;
int head[N],cnt=0;
ll c[11],s[11][N];
int b[N][N],d[N][N];
int f[N];
ll ans=0;
struct gd
{
   int x,y;
   ll dis;
}a[500005];
bool cmp(gd a,gd b)
{
   return a.dis<b.dis;
}
int find(int u)
{
   if(f[u]!=u) return find(f[u]);
   return u;
}
int main()
{
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   scanf("%d%d%d",&n,&m,&k);
   memset(b,-1,sizeof(b));
   for(int i=1;i<=m;i++)
   {
     int u,v,w;
     scanf("%d%d%d",&u,&v,&w);
     if(u>v) swap(u,v);
     if(b[u][v]==-1)
     {
       t++;
       d[u][v]=t;
       b[u][v]=w;
       a[t].x=u; a[t].y=v; a[t].dis=w;
       continue;
     }
     if(w<b[u][v])
     {
        b[u][v]=w;
        a[d[u][v]].dis=w;
     }
   }
   for(int i=1;i<=k;i++)
   {
     scanf("%lld",&c[i]);
     for(int j=1;j<=n;j++)
       scanf("%lld",&s[i][j]);
   }
   for(int i=1;i<=n;i++)
     for(int j=i+1;j<=n;j++)
     {
       ll p=0x7fffffff;
       for(int v=1;v<=k;v++)
         p=min(p,(ll)(c[v]+s[v][i]+s[v][j]));
       if(b[i][j]==-1)
       {
          b[i][j]=p;
          a[++t].x=i; a[t].y=j; a[t].dis=p;
          continue;
       }
       if(p<b[i][j])
       {
          b[i][j]=p;
          a[d[i][j]].dis=p;
       }
     }
   sort(a+1,a+t+1,cmp);
   for(int i=1;i<=n;i++)
     f[i]=i;
   for(int i=1;i<=t;i++)
   {
     int tx=find(a[i].x);
     int ty=find(a[i].y);
     if(tx!=ty)
     {
        f[tx]=f[ty];
        ans+=a[i].dis;
     }
   }
   cout<<ans;
   return 0;
}

