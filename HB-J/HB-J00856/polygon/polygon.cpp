#include<bits/stdc++.h>
using namespace std;

freopen(polygon.in,"r",std);
freopen(polygon.out,"w",std);

int main(){
int n,l[5007],i=0,s=0,j,z;
cin>>n;
while(i-n){
i++;
cin>>l[i];
}

if(n==3){
if(l[1]+l[2]>l[3]){
cout<<1;
}else{
cout<<0;
}
}

sort(l+1,l+n);
if(l[n]==1&&n>3){
i=2;
while(i-n+1){
j=-1;
i++;
z=1;
while(j-i){
j++;
z=(z*(n-j))%998244353;
}
s=(s+z)%998244353;
}
cout<<s;
}

//if(n>3&&l[n]!=1){}
return 0;
}
