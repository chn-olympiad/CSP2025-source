#include<bits/stdc++.h>
using namespace std;
int a[105];
int c,r,n,m,qwe;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
cin>>n>>m;
cin>>qwe;
a[1]=qwe;
for(int i=2;i<=n*m;i++){
cin>>a[i];
}
sort(a,a+(n*m)+1);
for(int i=n*m;i>=1;i--){
if(a[i]==qwe){
        i=(n*m)-i+1;
int sum=i/(n*2);
i=i%(n*2);
if(i<=n){
c=(sum*2)+1;
r=i;
cout<<c<<" "<<r;
return 0;
}
if(i>n){
i=i-2;
r=n-i+1;
c=sum+2;
cout<<c<<" "<<r;
return 0;
}
}
}
return 0;
}
