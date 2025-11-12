#include<bits/stdc++.h>
using namespace std;
int cmp(int a ,int b){
if(b>a){
    return a>b;
}
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);
   int n,m,b[10005],x,t=0,s=0,heng,shu;
   cin>>n>>m;
   for(int i=1;i<=n*m;i++){
    cin>>b[i];
    x=b[1];
   }
   sort(b+1,b+n*m+1,cmp);
   for(int i=1;i<=n*m;i++){
    if(b[i]==x){
        t=i;
        break;
    }
   }
   if(t%n==0){
    shu=t/n;
   }else{
   shu=t/n+1;
   }
   if(t%(2*n)>n){
    int o=t%(2*n);
    o-=n;
    heng=n-o+1;
   }else{
   heng=t%(2*n);
   }
   cout<<shu<<" "<<heng;
return 0;
}
