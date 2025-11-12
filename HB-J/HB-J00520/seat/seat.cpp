#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  int n,m,g,q=0,w=0,l=0;//n shi hang,m shi lei
  cin>>n>>m;
  for(int i=1;i<=n*m;i++)
  {
    cin>>a[i];
  }
  g=a[1];
  for(int j=1;j<=100;j++)
  {
     for(int i=n*m+1;i>0;i--)
    {
        if(a[i-1]<a[i])
        {
            q=a[i-1];
            a[i-1]=a[i];
            a[i]=q;
        }
    }
  }
  for(int i=0;i<=n*m-1;i++)
  {
    if(a[i]==g)
    {
        w=i+1;
    }
  }
  if(w<=n)
  {
      cout<<"1"<<" ";
      l=1;
  }
  else
  {
    if(w/n>=1&&w%n!=0)
    {
        cout<<w/n+1<<" ";
        l=w/n+1;
    }
    else
    {
       if(w%n==0)
       {
           cout<<w/n<<" ";
           l=w/n;
       }
    }
  }
  if(l%2==0)
  {
      if(w%n!=0)
      {
          cout<<(n+1)-w%n;

      }
      else
      {
          cout<<"1";
      }
  }
  else
  {
      if(w%n!=0)
      {
          cout<<w%n;
      }
      else
      {
          cout<<n;
      }
  }
  return 0;
}
