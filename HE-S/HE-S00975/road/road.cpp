#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u[1000005],v[1000005],w[1000005];
long long c[100000005],a[10005][10005];
long long ans;
int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);  
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
  for(int i=1;i<=k;i++) 
  {
  	cin>>c[i];
  	for(int j=1;j<=n-1;j++) cin>>a[i][j];
  }
  if(k<=0)
  {
  	for(int i=1;i<=m;i++) ans+=w[i];
  	cout<<ans<<endl;
  }
  for(int i=1;i<=m;i++) ans+=w[i];
  for(int i=1;i<=k;i++) 
  {
  	for(int j=1;j<=n-1;j++)
  	{
  	  if(c[i]+a[u[i]][j]+a[v[i]][j]<w[i]) ans=ans-w[i]+c[i]+a[u[i]][j]+a[v[i]][j];
	}
  }
  cout<<ans<<endl;
  return 0;
} 
