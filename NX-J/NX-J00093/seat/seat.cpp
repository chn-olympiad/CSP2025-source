#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
      int n,m;
      cin>>n>>m;
      int u=0;
      for(int i=1;i<=n*m;i++)
      {
          cin>>a[i];
          if(i>1)
          {
              if(a[i]>a[1])
                u++;
          }

      }
      u++;

      int hang=0,lie=0;
      if(u<=n)lie=1;
      else
      {
          if(u%n==0)lie=u/n;
          else lie=u/n+1;
      }
      if(u%n==0)u=n;
      else u=u%n;
      if(lie%2==0)
      {
          hang=n-u+1;
      }
      else hang=u;
      cout<<lie<<" "<<hang;
      return 0;

}
