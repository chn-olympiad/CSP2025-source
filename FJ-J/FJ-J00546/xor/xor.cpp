#include <bits/stdc++.h> 
using namespace std;
int main(){
//    freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
 int a ,b;
   cin>>a>>b;
   int c[a+10];
   for(int d=0;d<a;d++){
   	cin>>c[d];  
   }
   int remenber=0,k=0,ans=0;
   for(int f;f<a;f++){

   	for(int g=f;g>0;g--){
   		k=k^c[g];
		   
   		if(g=remenber){
   			ans+1;
   			break;
		   }
   		if(k=b){
   			ans+1;
   			remenber=k;
   			break;
		   }
		   
	   }
   } 

   	
   
   cout<<ans;
   return 0;
}
