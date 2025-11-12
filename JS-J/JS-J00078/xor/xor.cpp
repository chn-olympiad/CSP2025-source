#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,k,b[200005],c[200005],y;
int main()
{
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin>>n>>k;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
   }
   for(int i=1;i<=n;i++)
   {
       long long s=0;
       for(int j=i;j<=n;j++)
       {
           s=(s^a[j]);
           if(s==k)
           {
               b[i]=j;
               break;
           }
       }
       if(b[i]==0)
       {
           b[i]=n+1;
       }
   }
   c[n+1]=1;
   for(int i=n;i>=1;i--)
   {
       bool q=0;
       for(int j=i;j<=b[i];j++)
       {
           if(c[j]==1)
           {
               q=1;
               break;
           }
       }
       if(q==0)
       {
           y++;
           c[i]=1;
       }
   }
   cout<<y<<endl;
   return 0;
}
