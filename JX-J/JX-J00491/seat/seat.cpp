#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{     freopen("seat.in","r",stdin);
      freopen("seat.out","w",stdout);
     cin>>n>>m;
     for(int i=1;i<=n*m;i++)
     {
          cin>>a[i];
     }
     int k=a[1];
     int yyz;
     sort(a+1,a+n*m+1,cmp);
     for(int i=1;i<=n*m;i++)
     {
         if(a[i]==k)
         {
             yyz=i;
         }
     }
      int ls=yyz/n,hs;
      
      if(yyz%n!=0) ls++;
      
      yyz=yyz%n;
      
    if(ls%2==1)
    {
        if(yyz==0) hs=n;
        hs=yyz+1;

    }
     else
     {
         if(yyz==0) hs=1;
         else hs=n-yyz+1;
     }
     cout<<ls<<" "<<hs;
    return 0;
}