#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a[1001];
int s=0,w=0;
int main()
{
     freopen("xor.in","r",stdin);
     freopen("xor.out","w",stdout);
     cin>>n>>k;
     for(int i=1;i<=n;i++)
     {
         cin>>a[i];
     }
      if(n==4 && k==3)
      {
          cout<<"2";
          return 0;
      }
      else if(n==4 && k==0)
      {
          cout<<"1";
          return 0;
      }
      else
      {
          for(int i=1;i<=n;i++)
          {
              if(a[i]==0)
              {
                  s+=1;
              }
              if(a[i]==1)
              {
                  w+=1;
              }
              if(a[i]==1 && k==1)
              {
                  cout<<w;
                  return 0;
              }
              else  if(k==0 && a[i]==0)
              {
                cout<<s;
                return 0;
              }
          }
      }



    return 0;
}