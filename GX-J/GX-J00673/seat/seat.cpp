#include <bits/stdc++.h>
using namespace std;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   long unsigned int n,m,i=1,s=1,ans;
cin>>n>>m;
   int b[n*m];
cin>>b[n*m];
   while(i<=m*n){
   i++;
   if(b[i]>b[1])
       s++;
       else
       return 0;
   }
   
  if(s%2==0)
     ans=n+1-s;
     else
     ans=s%2;
   cout<<s/n<<ans;
   return 0;
}
