#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
   int t,n,a[10000],b[10000],c[10000],s=0,am=0,bm=0,cm=0,ans=0;
   cin>>t;
   for(int i=1;i<=t;i++){
      cin>>n;
      for(int j=1;j<=n;j++){
         cin>>a[i]>>b[i]>>c[i];
         if(n=2){
         if(am<=n/2){
             s+=a[i];
             am++;
           }
           if(am>n/2){
             am--;
           if(s>=10){
               s-=a[i];}
            else{
                s--;
            }
      }
      }}cout<<s<<endl;
      s=0;
      am=0;
   }
   return 0;
}
