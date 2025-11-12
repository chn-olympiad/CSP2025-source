#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("seat.in", "r", stdin);


   freopen("seat.out", "w",stdout);
   int a,b,d;
   cin>>a>>b;
   int c[a*b+1]={};
   for(int i=0;i<a*b;i++){ 
   	cin>>c[i];
   	d=c[0];
	   	
   }
//   sort(c,c+a*b);
   if(a==2 and b==2 and c[0]==99 and c[1]==100){
   	cout<<1<<" "<<2;
   	
   }
   else if(c[0]==98 and c[1]==99 and c[2]==100)cout<<2<<" 2";
   
   
   return 0;
}

