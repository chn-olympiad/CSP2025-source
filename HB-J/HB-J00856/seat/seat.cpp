#include<bits/stdc++.h>
using namespace std;

freopen(seat.in,"r",std);
freopen(seat.out,"w",std);

int main(){
int n,m,c[107],i=1,R,nm,s=1;
cin>>n>>m;
nm=n*m;
cin>>c[i];
R=c[i];
while(i-nm){
i++;
cin>>c[i];
if(c[i]>R){
s++;
}
}
if(s<=n){
cout<<1<<" "<<s;
}else{
int l=(s-1)/n+1;
s=(s-1)%n+1;
cout<<l<<" ";
if(l%2==0){
cout<<n-s+1;
}else{
cout<<s;
}
}
return 0;
}
