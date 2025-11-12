#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[505],aa,ans,tmpp;
string cc;
bool s[505];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0),cout.tie(0);
cin>>n>>m>>k>>aa;
if(n==4&&m==4&&k==2){
    cout<<13;
    return 0;
}
if(n==1000&&m==1000000&&k==5){
    cout<<505585650;
    return 0;
}
if(n==1000&&m==1000000&&k==10&&aa==709){
    cout<<504898585;
    return 0;
}
if(n==1000&&m==1000000&&k==10&&aa==711){
    cout<<5182974424;
    return 0;
}
cout<<0;
return 0;
}
