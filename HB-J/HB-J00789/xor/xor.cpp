#include<iostream>
using namespace std;
int a[230],a1[2120],cur=0,sad=0;
int co[10005];
int main()
{
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   int n,k,ans=0;
   cin>>n>>k;
   for(int i=1;i<=n;i++) cin>>a[i];
   if(k==0)
   {
       for(int i=1;i<=n;i++)
       {
           for(int j=i+1;j<=n;j++)
           {
               ans++;
           }
       }
       cout<<ans;
       return 0;
   }
   else
   {
       int cur=0;
       for(int i=1;i<=n;i++)
       {
           for(int j=i+1;j<=n;j++)
           {
               int sum=a[i];
               for(int k=i;k<=j;k++)
               {
                   sum=(sum^a[k]);
               }
               cur++;
               a1[cur]=sum;
           }
       }
       for(int i=1;i<=cur;i++)
       {
          co[a1[i]]++;
       }
       for(int i=1;i<=cur;i++)
       {
          if(co[a1[i]]==2) sad++;
       }
       cout<<sad;
   }
}
