#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[3000000];
int ls[3000000];
struct node{
    int u,v,w;
};
bool cmp(node x,node y)
{
    return x.w<y.w;
}
node g[3000001];
int xfind(int x)
{
    if(fa[x]==x)
        return x;

    fa[x]=xfind(fa[x]);return fa[x];
}
int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
  cin>>n>>m>>k;
  long long ans=0;
  for(int i=1;i<=n;i++)
    fa[i]=i;
  for(int i=1;i<=m;i++)
  {
      int u,v,w;
      cin>>u>>v>>w;
      g[i]={u,v,w};
  }
        for(int i=1;i<=k;i++)
        {
            int c=0;
            cin>>c;
            queue<int> q;
            bool flag=0;
            for(int j=1;j<=n;j++)
            {
                cin>>ls[j];
                if(ls[j]==0)
                    {q.push(j);flag=1;}

            }
            if(flag)
            while(!q.empty())
            {
                for(int j=1;j<=n;j++)
                {
                   // if(ls[j]!=0)
                    g[++m]={q.front(),j,ls[j]};

                } q.pop();
            }
        }



        sort(g+1,g+1+m,cmp);
    int idx=0;
  for(int i=1;i<=m;i++)
  {
      if(idx==n-1)
        break;
      if(xfind(fa[g[i].u])!=xfind(fa[g[i].v]))
      {
          fa[xfind(g[i].u)]=xfind(fa[g[i].v]);
          ans+=g[i].w;
          idx++;
      }
  }
  cout<<ans;

    return 0;
}
