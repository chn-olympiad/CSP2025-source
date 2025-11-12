#include<bits/stdc++.h>
using namespace std;
int c[100];
int px(int a,int b){
	return a>b;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   int a,b,d;
   cin>>a>>b;
   for(int i=1;i<=a*b;i++){
      cin>>c[i];
   }
   d=c[1];
   sort(c+1,c+a*b+1,px);
   int e;
   for(int i=1;i<=a*b;i++){
      if(c[i]==d) e=i;
   }
   if(e/b%2==1){
	   if(e%a!=0) e=a*(e/a+1);
	   cout<<e/a<<" "<<e/b+1;
   }
   else{
	   if(e%a!=0) e=a*(e/a+1);
	   cout<<e/a<<" "<<a-e/b+1;
   }
   return 0;
 }
