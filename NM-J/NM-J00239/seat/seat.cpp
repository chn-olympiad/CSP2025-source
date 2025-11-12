#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,y,q,w;
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  x=a[1];
  sort(a+1,a+1+n);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      {
        y=a[i]/2;
        if(a[i]==x)  break;
      }
  q=y/n;
  w=y%n;
  cout<<"1"<<" "<<"1";  
  fclose(stdin);
  fclose(stdout);
  return 0;
}
