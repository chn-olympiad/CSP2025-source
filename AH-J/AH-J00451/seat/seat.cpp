#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000];
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   int u=0;
   for(int i=1;i<=n*m;i++){
	   cin>>a[i];
   }
   u=a[1];
   int p=0;
   sort(a+1,a+n*m+1);
   for(int i=n*m;i>=1;i--){
	   if(a[i]==u){
		   p=i;
		   break;
	   }
   }
   p=m*n-p+1;
   int a1=p/m;

   if(p%m!=0){
	   a1++;
	   if(a1%2==0){
		   cout<<a1<<" "<<m-(p%m)+1;
	   }
	   else{
		   cout<<a1<<" "<<p%m;
	   }
   }
   else{
	  if(a1%2==0){
		  cout<<a1<<" "<<1;
	  }
	  else{
		  cout<<a1<<" "<<m;
	  }
   }  
   
   return 0;
}
