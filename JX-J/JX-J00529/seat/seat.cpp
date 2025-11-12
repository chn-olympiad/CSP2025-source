#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   int a,b,c,d;
   cin>>a;
   cin>>b;
   cin>>c;
   int max=100;
   d=max-c;
   if(d==a){
        cout<<b<<" "<<a;

   }else if(d>a){
        cout<<b<<" "<<a-2;
   }else if(d<a){
        cout<<b-d<<" "<<a;
   }
   return 0;



}
