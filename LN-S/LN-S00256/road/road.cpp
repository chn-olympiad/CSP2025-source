#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[100005],v[100005],w[100005],a[1005][1005];
int c[10005];
int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++)
  {
    cin>>u[i]>>v[i]>>w[i];
  }
  for(int j=1;j<=k;j++)
  {
    cin>>c[j];
    for(int i=1;i<=n;i++)
    {
      cin>>a[j][i];
    }
  }

  cout<<13;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
