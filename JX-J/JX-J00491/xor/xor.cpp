#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n,k;
int ans=0;
int main()
{     freopen("xor.in","r",stdin);
      freopen("xor.out","w",stdout);
     
     cin>>n>>k;
     for(int i=1;i<=n;i++)
     {
         cin>>a[i];
         if(a[i]==k) ans++;
         a[i]=0;
     }
     if(k==0)
     {
         cout<<ans;return 0;
     }
     if(k==1)
     {
         cout<<ans;return 0;
     }
     int j=1;
     while(j<=n)
     {
         
         int yyz=j;
         if(a[j]>k)
         {
             break;
         }
         else
         {   int h=a[j];
             while(h<=k)
             {    
                 if(h==k)
                 {    ans++;
                     break;
                 }
                 
                 if(h+a[j+1]<=k)
                 {    j++;
                     h+=a[j];
                 }
                 else
                 {   j=yyz+1;
                     break;
                 }
             }
         }
         
     }
     cout<<ans;
    return 0;
}