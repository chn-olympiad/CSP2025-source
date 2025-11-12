
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100001],f[1000001][1000001];
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  int ans;
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  sort(a+1,a+n+1);
    for(int i=1;i<=n-2;i++)
    {
      int m=a[i]*2;
      for(int j=1;j<=a[i];j++)
        for(int k=j+1;k<=a[i];k++)
        {
          f[j][k]=f[j][k-1]+a[k];
          if(f[j][k]>m)
            ans++;
        }
    }
  cout<<ans;
  return 0;
 }

