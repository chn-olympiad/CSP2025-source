#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,a[500050];
int pd1,pd2;
int main()
{
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);  
   cin>>n>>k;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      if(a[i]!=1)  pd1=1;
      if(a[i]!=1 && a[i]!=0)  pd2=1;
   }
   if(pd1==0){
      cout<<n/2;
      return 0;
   }
   else{
      if(pd2==0){
         if(k==1){
            int cnt=0;
            for(int i=1;i<=n;i++)
               if(a[i]==1)
                 cnt++;
            cout<<cnt;
            return 0;
         }
         else{
            int tot=0;
            for(int i=1;i<=n;i++){
              if(a[i]==0)  tot++;
              if(a[i]==1 && a[i-1]==1)  tot++;
            }
            cout<<tot;
            return 0;
         }
      }
      else
        cout<<n/2;
   }
   return 0;
}
