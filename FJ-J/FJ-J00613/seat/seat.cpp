#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int p,int q){
return p>q;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,k,x,y;
cin>>n>>m;
for(int i=1;i<=n*m;i++){
cin>>a[i];
}
k=a[1];
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=n*m;i++){
if(a[i]==k){
x=ceil(i*1.0/n);
y=i%n;
if(y==0)y=n;
if(x%2==0){
y=n-y+1;
}
break;
}
}
cout<<x<<" "<<y;
return 0;
}
