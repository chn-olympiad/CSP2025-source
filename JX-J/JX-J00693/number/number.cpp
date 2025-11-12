#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int i=0,a,b[10000],d=0;
cin>>a;
while(1){
b[i]=a%10;
a=a/10;
i++;
d++;
if(a<10){
break;
}
}
sort(b,b+i);
for(int i=d-1;i>=0;i--){
cout<<b[i];
}
cout<<a;
return 0;
}
