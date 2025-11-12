#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  int n,a[100],sum=0;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)
  {
    if((a[i]+a[i+1]+a[i+2]>2*a[i+2]) && (n/2+1>=i))
      sum+=1;
    if((a[i]+a[i+1]+a[i+2]+a[i+3]>2*a[i+3]) && (i+3=<n))
      sum+=1;
    if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>2*a[n])
      sum+=1;
  }
  cout<<sum
}
