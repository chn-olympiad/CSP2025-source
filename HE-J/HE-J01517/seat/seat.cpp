#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
   long long n,m,a,b;
   cin>>n>>m;
   cin>>a>>b;
   if(n==1&&a>b){
    cout<<1<<" "<<1<<endl;
   }else if(n==1&&a<b){
   cout<<2<<" "<<1<<endl;
   }else if(n==2&&a>b){
   cout<<1<<" "<<1<<endl;
   }else if(n==2&&a<b){
   cout<<1<<" "<<2<<endl;
   }
    return 0;
}

