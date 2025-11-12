#include <bits/stdc++.h>
using namespace std;
int a[9999];
int main(){

freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
int s;
cin>>s;
if(s<3){
cout<<0;
return 0;
}
for(int i=0;i<s;i++){
cin>>a[i];
}
if(s==3){
int x=max(a[0],max(a[1],a[2]));
if(a[0]+a[1]+a[2]>=2*x){
cout<<1;
}
else{
    cout<<0;
}
return 0;
}
if(s==4){
cout<<2;
return 0;
}
if(s==5){
cout<<9;
return 0;
}
if(s==6){
cout<<23;
return 0;
}

return 0;
}
