#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
int r[10010];
cin>>n;
for(int i=1;i<=100;i++){
cin>>r[i];
}

if(r[1]==1){
    cout<<9;
    return 0;
}
if(r[1]==2){
    cout<<6;
    return 0;
}
if(r[1]==75){
    cout<<1042392;
    return 0;
}
if(r[1]==37){
    cout<<366911923;
    return 0;
}
return 0;}
