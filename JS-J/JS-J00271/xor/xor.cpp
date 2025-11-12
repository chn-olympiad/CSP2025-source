#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200001],i,cnt,x;
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin>>n>>k;
   for(i=0;i<n;i++){
        cin>>a[i];
   }
   if(k==1){
        for(i=0;i<n;i++){
            if(a[i]==1)cnt++;
        }
   }else{
        for(i=0;i<n;i++){
            if(a[i]==0){
                cnt++;
                cnt+=x/2;
                x=0;
            }else{
                x++;
            }
        }
   }
   cout<<cnt+x/2;
   return 0;
}
