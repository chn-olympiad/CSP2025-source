#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5001],s=-1,ans=0;
signed main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
   int n;
   cin>>n; 
   if(n<3){
   	  cout<<0;
   	  return 0;
   }
   for(int i=1;i<=n;i++){
   	   cin>>a[i];
   	   s=max(s,a[i]);
   	   ans+=a[i];
   }
   if(ans>s*2){
   	   cout<<1;
   }
}
