#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("polygon.in","r",stdin)
  freopen("polygon.out","w",stdout)
  int n;
  int a[5002];
  cin>>n;
  for(int i=1;i<=n;i++)
  cin>>a[i];
  sort(a+1,a+n+1);
  cout<<2*n-1;
  return 0;
}
