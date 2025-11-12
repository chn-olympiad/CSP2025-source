#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   int a[(n*m)+1],rfn,rn,rm,rp;
   for(int i=1;i<=n*m;i++){
	   cin>>a[i];
   }
   rfn=a[1];
   sort(a+1,a+m*n+1);
   for(int i=1;i<=n*m;i++){
	   if(a[i]==rfn){
		   rp=i;
		   break;
	   }
   }
   //for(int i=1;i<=n*m;i++)cout<<i<<" "<<a[i]<<endl;
   //rm=m-(rp/n);
   if(rp%n==0)rm=m-(rp/n)+1;
   if(rp%n!=0)rm=m-(rp/n);
   if(rm%2!=0){
	   if(rp%n==0){
		   rn=1;
	   }
	   if(rp%n!=0){
		   rn=n-rp%n+1;
	   }
   }
   if(rm%2==0){
	   if(rp%n==0){
		   rn=n;
	   }
	   if(rp%n!=0){
		   rn=1+rp%n-1;
	   }
   }
   cout<<rm<<" "<<rn<<endl;
   return 0;
}
