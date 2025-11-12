#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  int n,m;
  cin>>n>>m;
  int a[n][m],sum[n*m];
  for(int i=1;i<=n*m;i++)
    cin>>sum[i];
  sort(sum+1,sum+n*m+1);
}
