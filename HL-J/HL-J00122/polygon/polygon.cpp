#include<iostream>
using  namespace std;
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
   int n,a,b,c;
   cin>>n>>a>>b>>c;
   if(n==3){
   if(a+b>c&&b+c>a&&a+c>b){
   	cout<<"1\n";
   }	
   else{
   	cout<<"0\n";
   }
   }
   else{
   	long long ans=0;
   	for(int i=2;i<=n;i++) ans=ans+(n-i);
   	cout<<ans; 
   }
   return 0;
}
