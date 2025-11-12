#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],r,b[20][20],sum;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   int temp=n*m;
   for(int i=1;i<=temp;i++)
   {
       cin>>a[i];
   }
   r=a[1];
   sort(a+1,a+1+temp,cmp);
   for(int i=1;i<=m;i++)
   {
       if(i%2==1)
       {
           for(int j=1;j<=n;j++)
           {
               b[j][i]=a[++sum];
               if(b[j][i]==r)
               {
                   cout<<i<<" "<<j;
                   return 0;
               }
           }
       }
       else if(i%2==0)
       {
           for(int j=n;j>=1;j--)
           {
               b[j][i]=a[++sum];
                if(b[j][i]==r)
               {
                   cout<<i<<" "<<j;
                   return 0;
               }
           }
       }
   }//ceil

    return 0;
}
