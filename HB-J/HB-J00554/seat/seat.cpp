#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen(seat.in,"r",stdin);
freopen(seat.out,"w",stdout);
int n,m;
cin>>n>>m;
int a[n*m];
for(int i=1;i<=n*m;i++)
{
cin>>a[i];
}
int z=a[0];
cin>>z;
sort(a+1,a+n*m+1);
for(int i=1;i<=n*m;i++)
{
if(a[i]==z)
{
  if(m%i==0)
  {
    cout<<m/i<<" "<<n;
  }
  else
  {
    if((m/i+1)%2==0)
    {
      cout<<m/i+1<<" "<<n-m%i+1;
    }
    else
    {
      cout<<m/i+1<<" "<<m%i;
    }
  }
}
}
  return 0;
}
