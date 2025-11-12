#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
long long n,m,a[MAXN],c,r;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++){
	   cin>>a[i];
   }
   int s=a[1];
   sort(a+0,a+n*m);
   for(int i=n*m;i>=1;i--){
	   if(a[i]==s){
		   s=n*m-i;
		   break;
	   }
   }
   if(s%n==0) c=s/n;
   else c=s/n+1;
   if(c%2!=0){
	   if(s%n==0) r=n;
	   else r=s%n;
   }else{
	   if(s%n==0) r=1;
	   else r=n-(s%n)+1;
   }
   cout<<c<<" "<<r; 
   fclose(stdin);
   fclose(stdout);
   return 0;
}
