#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon1.in","r",stdin);
freopen("polygon1.out","w",stdout);
int n,plan=0,q,w,e;
int a[5001]={};
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
int af,be,cr;
for(int i=1;i<=n;i++){
    if(a[i]>4) {af=a[i];
    if(a[i]>8){
        be=af;
        if(a[i]>15){
            cr=be;
        }}}
   if(cr+cr<q+w+e){
    plan++;
   }
}
int y=plan%998244353;
cout<<y;
return 0;
}
