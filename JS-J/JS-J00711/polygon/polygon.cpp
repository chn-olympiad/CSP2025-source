#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,zs;
long long int mq,cnt;
int a[N];
int main()
{
      freopen("polygon.in","r",stdin);
      freopen("polygon.out","w",stdout);
      cin>>n;
      for(int i=1;i<=n;i++)
      {
          cin>>a[i];
      }
      sort(a+1,a+1+n);
      if(n<=3)
      {
           zs=a[1]+a[2]+a[3];
           if(zs>2*a[n])cout<<'1';
           else cout<<'0';
           return 0;
      }
      for(int i=3;i<=n;i++)
      {
          for(int j=i-1;j>=1;j--)
          {
              mq+=a[j];
              if(mq>a[i])
              {
                  cnt+=j;
                  mq=0;
              }
          }
      }
      cout<<cnt+1;
      return 0;
}
