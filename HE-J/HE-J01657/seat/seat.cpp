#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,r,z;
int a[101],b[101]={};
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=0;i<=m*n-1;i++)
   {
       cin>>a[i];
       b[i]=a[i];

   }
   b[0]=a[0];

   for(int i=0;i<=m*n-2;i++)
   {
       for(int o=0;o<=m*n-2-i;o++)
       {
           if(a[o]<=a[o+1])
           {
               k=a[o];
               a[o]=a[o+1];
               a[o+1]=k;

           }

       }


   }
   for(int i=0;i<=m*n-1;i++)
   {
       if(a[i]==b[0])
       {
           k=i+1;

       }
   }

   if(k%n==0)
   {
       c=k/n;

   }
   else
    {
        c=k/n+1;
    }
    if(c%2==0)
   {
        r=k%n;

        r=n-r+1;
       r=r%n;
   }
   else
    {
        r=k%n;
        if(r==0)
        {

            r=n;
        }
    }
   cout<<c<<" "<<r<<endl;

    return 0;
}
