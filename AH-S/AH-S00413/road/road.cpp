#include<bits/stdc++.h>
using namespace std;
long long u,v,w,n,m,k,c,t,e[10005][10005];
int main()
{
 freopen("road.in","r",stdin);
 freopen("road.out","w",stdout);
  memset(e,0x3f,sizeof(e));
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
	  cin>>u>>v>>w;
	  e[u][v]=e[v][u]=min(e[u][v],w);
  }
  for(int i=1;i<=k;i++)
  {
	  cin>>t;
	  for(int j=1;j<=n;j++)
	  {
		  e[i][j]=e[j][i]=0;
	  }
  }
  for(int i=1;i<=n;i++)
  {
	  for(int j=i+1;j<=n;j++)
	  {
		  c=c+e[i][j];
	  }
  }
  cout<<c;
}
//Ren5Jie4Di4Ling5%
