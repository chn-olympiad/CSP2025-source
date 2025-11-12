#include<bits/stdc++.h>
using namespace std;
namespace leo {
  struct node {
    int x,y,z;
    _Bool operator<(const node n) const{
	  return z<n.z;
	}
  };
  int n,m,k,special;
  long long ans;
  int c[15],a[15][20005],chosen[15],fa[20005],size[20005];
  node e[2000005];
  int find(int x) {
    if(fa[x]==x)
      return x;
    return fa[x]=find(fa[x]);
  }
  void kruskal(long long cost,int m) {
    long long res=cost;
    int cnt=n;
    static node edge[2000005];
    memcpy(edge,e,sizeof(node)*(m+1));
    for(int i=1;i<=k;i++)
      if(chosen[i]) {
        cnt++;
        for(int j=1;j<=n;j++)
          edge[++m]=(node){cnt,j,a[i][j]};
	  }
	sort(edge+1,edge+m+1);
	for(int i=1;i<=cnt;i++) {
	  fa[i]=i;
	  size[i]=1;
	}
	for(int i=1,k=0,x,y;i<=m;i++) {
	  x=find(edge[i].x); y=find(edge[i].y);
	  if(x^y) {
	    if(size[x]<size[y])
	      swap(x,y);
	    size[x]+=size[y];
	    fa[y]=x;
	    k++;
	    res+=edge[i].z;
	    if(res>ans)
	      break;
	    if(k==cnt-1)
	      break;
	  }
	}
	ans=min(ans,res);
  }
  void dfs(int i,long long cost=0) {
    if(cost>ans)
      return;
    if(i>k) {
      kruskal(cost,m);
      return;
	}
    dfs(i+1,cost);
    chosen[i]=1;
    dfs(i+1,cost+c[i]);
    chosen[i]=0;
  }
  void solve() {
    freopen("road.in","r",stdin);
    freopen("road.out","w+",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
      cin>>e[i].x>>e[i].y>>e[i].z;
    special=true;
    for(int i=1;i<=k;i++) {
      cin>>c[i];
      if(c[i])
        special=0;
      for(int j=1;j<=n;j++)
        cin>>a[i][j];
	}
	ans=0x3F3F3F3F3F3F3F3Fll;
	if(special) {
	  for(int i=1;i<=k;i++)
	    chosen[i]=1;
	  kruskal(0,m);
	}
	else
	  dfs(1);
    cout<<ans<<'\n';
  }
}
int main() {
  leo::solve();
}

