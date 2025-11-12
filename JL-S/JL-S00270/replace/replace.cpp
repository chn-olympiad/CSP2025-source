#include <bits/stdc++.h>
using namespace std;

int main(){
   freopen("replace.in","r",stdin);
   freopen("replace.out","w",stdout);
   long long n,s1,s2,s3,x,y,z;
   cin>>n>>s1>>s2>>x>>z;
   for(int i=0;i<=n;i++){
     if(y==s1){
		 y=s2;
	 }
	 else{
		y=y+0; 
	 }
   }
   s3=x+y+z;
   cout<<s3;
   return 0;
}
