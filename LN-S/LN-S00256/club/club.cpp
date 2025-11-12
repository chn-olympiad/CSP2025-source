#include<bits/stdc++.h>
using namespace std;
int t;
int a[100005][5];
int x,y,z;
int sum;
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>t;
  for(int i=1;i<=t;i++)
  {

    int n;
    cin>>n;
    for(int j=1;j<=n;j++)
    {
      cin>>a[j][1]>>a[j][2]>>a[j][3];
    }

    for(int j=1;j<=n;j++)
    {
      if(a[j][1]>a[j][2]&&a[j][1]>a[j][3]&&x+1<=n/2)
      {
        x++;
        sum+=a[j][1];
      }
      else if(a[j][1]<a[j][2]&&a[j][2]>a[j][3]&&a[j][2]&&y+1<=n/2)
      {
        y++;
        sum+=a[j][2];
      }
      else if(a[j][3]>a[j][1]&&a[j][3]>a[j][2]&&z+1<=n/2)
      {
        z++;
        sum+=a[j][3];
      }
    }

    cout<<sum;
    sum=0;

    x=0,y=0,z=0;
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
