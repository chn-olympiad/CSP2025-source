#include<bits/stdc++.h>
using namespace std;
using i64=int64_t;
struct disjoint_set
{
  vector<int> fa;
  disjoint_set(int n):fa(n)
  {
    iota(fa.begin(),fa.end(),0);
  }
  int find(int u)
  {
    return u==fa[u]? u:fa[u]=find(fa[u]);
  }
  void merge(int u,int v)
  {
    u=find(u),v=find(v);
    if (u!=v) fa[u]=v;
  }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  int n,m,k;
  i64 minn=LLONG_MAX;
  cin>>n>>m>>k;
  vector<int> c(k+1);
  vector<vector<int>> a(k+1,vector<int>(n+1));
  vector<tuple<int,int,int>> edge(m);
  for (auto &[w,u,v]:edge)
    cin>>u>>v>>w;
  sort(edge.begin(),edge.end());
  for (int i=1;i<=k;i++)
  {
    cin>>c[i];
    for (int j=1;j<=n;j++)
      cin>>a[i][j];
  }
  for (int s=0;s<(1<<k);s++)
  {
    int it1=0,it2=0,cnt=n;
    i64 ans=0;
    vector<tuple<int,int,int>> e;
    for (int p=s;p;p&=p-1)
    {
      int i=__builtin_ctz(p)+1;
      ans+=c[i];
      for (int j=1;j<=n;j++)
        e.emplace_back(a[i][j],i+n,j);
    }
    disjoint_set dsu(n+k+1);
    sort(e.begin(),e.end());
    while (cnt>1)
    {
      int u,v,w;
      auto [u1,v1,w1]=edge[it1];
      if (e.empty()) u=u1,v=v1,w=w1;
      else 
      {
        if (it2<e.size())
        {
          auto [w2,u2,v2]=e[it2];
          if (w1<w2) 
          {
            u=u1,v=v1,w=w1;
            it1++;
          }
          else
          {
            u=u2,v=v2,w=w2;
            it2++;
          }
        }
      }
      if (dsu.find(u)==dsu.find(v)) continue;
      if (u<=n&&v<=n) cnt--;
      ans+=w;
      dsu.merge(u,v);
    }
    if (s==1) cout<<cnt<<'\n';
    minn=min(ans,minn);
  }
  cout<<minn<<'\n';
}
