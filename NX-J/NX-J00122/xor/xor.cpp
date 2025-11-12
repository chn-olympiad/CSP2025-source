#include <bits/stdc++.h>
using namespace std;
int a[9999],m=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
int s,n;
cin>>s>>n;
for(int i=1;i<s;i++){
cin>>a[i];
}
if(n==0){
for(int i=1;i<s;i++){
if(a[i]==0){
m++;
}
}
cout<<m;
}
return 0;
}
