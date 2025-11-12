#include<bits/stdc++.h> 
using namespace std;
long long n,m,z=1,a,b;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
cin>>a;
for(long long i=1;i<n*m;i++){
cin>>b;
if(b>a){
z++;
}
}
if(z%n==0){
cout<<z/n<<' ';
if(z/n%2==0){
cout<<1;
}
else{
cout<<n;
}
}
else{
cout<<z/n+1<<' ';
if((z/n+1)%2==0){
cout<<n-z%n+1;
}
else{
cout<<z%n;
}
}
return 0;
}
