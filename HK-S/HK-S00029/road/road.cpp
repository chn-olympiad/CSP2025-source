#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  long long n,m,k;
  cin >> n >> m >> k;
  long long u[m+5],v[m+5],w[m+5];
  for (int i =1; i<=m;i++)
  {
    cin >> u[i] >> v[i] << w[i];
  }
  long long c[k+5], a[k+5][n+5];
  for (int i=1,i<=k;i++)
  {
    cin >> c[i];
    for (int j=1;j<=n;j++)
    {
        cin >> a[i][j];
    } 
  }
  
  return 0;
}
