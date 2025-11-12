#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   int n,k,cnt=0;
   cin>>n>>k;
   for(int i=1;i<=n;i++){
     bool a;
     cin>>a;
     if(a==0)continue;
     else{
        cnt++;
     }
   }
   if(k==0){
    cnt /= 2;
   }
   cout<<cnt;
   return 0;
}

