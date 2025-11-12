#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
freopen("seat,r,in",stdin);
freopen("seat,w,out",stdout);
  int n,m,cnt=0,sum=0;
  cin>>n>>m;
  for(int i=2;i<=n*m;i++)
  if(a[i]>a[1])
  cnt++;
  cnt++;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
  {
    sum++;
    if(sum==cnt)
    cout<<i<<j;
  }
  return 0;
}

