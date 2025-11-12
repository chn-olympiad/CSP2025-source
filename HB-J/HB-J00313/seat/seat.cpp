#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,z,y,g,c,r;
void solve()
{
  std::cin>>n>>m;
  for(int i=1;i<=n*m;i++)
  {
      std::cin>>a[i];
      x=a[1];
  }
  for(int i=1;i<=n*m;i++)
  {
      if(a[i+1]>a[i])
      {
          int ans=0;
          ans=a[i];
          a[i]=a[i+1];
          a[i+1]=ans;
      }
  }
  for(int i=1;i<=n*m;i++)
  {
    if(a[i]==x)
    {
        g=i;
    }
  }
    z=g/n;
    y=g%n;
    if(y==0)
    {
        c=z;
    }
    else
    {
        c=z+1;
    }
    if(c%2==0&&y!=0)
    {
        r=n-y+1;
    }
    else if(c%2==0&&y==0)
    {
        r=1;
    }
    else if(c%2!=0&&y!=0)
    {
        r=y;
    }
    else if(c%2!=0&&y==0)
    {
        r=n;
    }
    std::cout<<c<<" "<<r<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    solve();
    return 0;
}
