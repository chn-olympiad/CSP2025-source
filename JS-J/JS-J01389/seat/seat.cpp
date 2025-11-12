#include <bits/stdc++.h>
using namespace std;
int n,m,r,k,h,l;
int a[105];
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=0;i<n*m;i++){
       cin>>a[i];
   }
   r=a[0];
   sort(a,a+n*m,greater<int>());
   for(int i=0;i<n*m;i++){
      if(r==a[i]){
         k=i+1;
         break;
      }
   }
   if(k%n!=0) l=k/n+1;
   else l=k/n;
   if(l%2==1){
      cout<<l<< " ";
      if(k%n!=0) cout<<k%n<<endl;
      else cout<<n<<endl;
   }
   if(l%2==0){
     cout<<l<< " ";
     cout<<n-k%n+1<<endl;
   }
   return 0;
}
