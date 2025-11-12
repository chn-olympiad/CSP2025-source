#include <bits/stdc++.h>
using namespace std;
int a[100],b[100],c[100],s[100],o[100];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
   int n,m,k,r,l,w=10000,sum=0;
   cin>>n>>m>>k;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
       cin>>b[i];
       cin>>c[i];
   }
   cin>>r;
   for(int i=0;i<n;i++)
   {
       cin>>s[i];
   }
   cin>>l;
   for(int i=0;i<n;i++)
   {
       cin>>o[i];
   }
   for(int i=0;i<n;i++)
   {
       if(c[i]<w)
       {
           w=c[i];
       }
   }
   for(int i=0;i<n;i++)
   {
       if(c[i]==w)
       {
           sum+=w;
           c[i]=0;
           w=0;
       }
       else if(c[i]<w)
       {
           w=c[i];
       }
   }
   sum+=w;
   w=0;
   for(int i=0;i<n;i++)
   {
       if(s[i]<w)
       {
           w=s[i];
       }
   }
   sum+=w;
   w=0;
   for(int i=0;i<n;i++)
   {
       if(o[i]<w)
       {
           w=o[i];
       }
   }
   sum+=w;
   w=0;
   cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
