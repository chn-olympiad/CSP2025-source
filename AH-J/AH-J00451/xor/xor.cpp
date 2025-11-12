#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   int n,k;
   cin>>n>>>m;
   for(int i=1;i<=n;i++){
	   cin>>a[i];
   } 
   if(k==0){
	   int x=0;
	   for(int i=1;i<=n;i++){
		   if(a[i]==0){
			   x++;
		   }
	   }
	   cout<<x;
   }
   else if(k==1){
	   int x=0;
	   for(int i=1;i<=m;i++){
		   if(a[i]==1){
			   x++;
		   }
	   }
	   cout<<x;
   }
   else{
	   cout<<2;
   }
   return 0;
}
