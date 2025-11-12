#include<bits/stdc++.h> 
using namespace std;
long long n,a[10005],b[10005],z,p=998244353;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(long long i=1;i<=n;i++){
cin>>a[i];
}
sort(a+1,a+1+n);
for(long long i=1;i<=n;i++){
b[i]=a[i]+b[i-1];
}
if(n==3){
if(a[1]+a[2]+a[3]>=a[3]*2){
cout<<1;
}
else{
cout<<0;
}
}
else if(a[n]==1){
cout<<(n*n%p-3*n%p+2)/2%p;
}
else{
for(long long l=3;l<=n;l++){
for(long long i=1;i<=n-l+1;i++){
long long r=i+l-1;
if(b[r]-b[i-1]>a[r]*2){
z++;
}
}
}
cout<<z%p;
}
return 0;
}
