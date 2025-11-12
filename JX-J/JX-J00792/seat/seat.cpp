#include<bits/stdc++.h>
using namespace std;
int a[1000],s[1000][1000];
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.ans","w",stdout);
  int n,m,c,r,xr,l=1;
  cin>>n>>m;
  for (int i=1;i<=n*m;i++)
      cin>>a[i];
  xr=a[1];
  for (int i=1;i<=n*m;i++)
    for (int j=1;j<=n*m;j++)
    {
          if (a[i]>a[j])
            swap(a[i],a[j]);
    }
  for (int i=1;i<=n;i++)
  {
      for (int j=1;j<=m;j++)
      {
          s[j][i]=a[l];
          l++;
      }
      i++;
      for (int j=m;j>=1;j--)
      {
          s[j][i]=a[l];
          l++;
      }
  }
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
      if (s[j][i]==xr)
      {
          c=i;
          r=j;
          break;
      }
  cout<<c<<' '<<r<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
