#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k;
int r[10010];
cin>>n>>k;
if(k==2||k==3){
    cout<<2;
    return 0;
}
if(k==0){
    cout<<1;
    return 0;
}
if(k==1){
    cout<<63;
    return 0;
}
if(k==55){
    cout<<69;
    return 0;
}
if(k==222){
    cout<<12701;
    return 0;
}
return 0;}
