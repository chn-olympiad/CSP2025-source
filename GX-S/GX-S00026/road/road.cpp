#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010;
const int MAXM=1000010;
int n,m,k;
int ans=0;
int tim=0;
bitset<MAXN> b;
struct edge
{
  int to,nxt,w;
}e[MAXM<<2];
int head[MAXN],cnt=0;
int vis[MAXN];
struct stst
{
  int w,now;
  bool operator <(const stst &x)const
  {
    return w>x.w;
  }
};
void add(int u,int v,int w)
{
  e[++cnt]=(edge){v,head[u],w};
  head[u]=cnt;
}
int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  memset(head,-1,sizeof(head));
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1; i<=n; i++)
  {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    add(u,v,w);
    add(v,u,w);
  }
  tim=n;
  priority_queue<stst>q;
  q.push((stst){0,1});
  int tot=0;
  for(int i=1; i<=k; i++)
  {
    int x;
    cin>>x;
    tim++;
    for(int j=1; j<=n; j++)
    {
      int w;
      scanf("%d",&w);
      add(tim,j,w);
      add(j,tim,w);
    }
  }
  while(!q.empty())
  {
    if(tot==n) break;
    stst x=q.top();
    q.pop();
    int u=x.now;
    if(vis[u]==1) continue;
    ans+=x.w;
    vis[u]=1;
    if(u>=1&&u<=n) tot++;
    for(int i=head[u]; ~i; i=e[i].nxt)
    {
      int v=e[i].to;
      q.push((stst){e[i].w,v});
    }
  }
  printf("%d",ans);
  return 0;
}
