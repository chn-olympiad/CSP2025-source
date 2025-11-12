#include<bits/stdc++.h>
using namespace std;
long long a[10001];
int main()
{
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   long long n,m;
   cin>>n>>m;
   for(int i=1;i<=n*m;i++)
   {
       cin>>a[i];
   }
   int h=a[1];
   sort(a+1,a+1+n*m);
   for(int i=n*m;i>=1;i--)
   {
       if(i==h)
       {
           if(i%n!=0)
           {

               if((i/n+1)%2==1)
               {
                   cout<<i%n<<" "<<i/n+1;
                   return 0;
               }
               else if((i/n+1)%2==0)
               {
                   cout<<n-(i%n)+1<<" "<<i/n+1;
                   return 0;
               }
           }
           else if(i%n==0)
           {
               cout<<n<<" "<<i/n;
               return 0;
           }
       }
   }
   return 0;
}
