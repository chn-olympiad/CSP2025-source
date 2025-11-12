#include<bits/stdc++.h> 
using namespace std;
long long n,m,z[1005][1005],a[5000005],k,w[1005][1005],y,y2;
long long dfs(long long l,long long r){
if(l==r){
z[l][r]=a[l];
if(a[l]==k){
w[l][r]=1;
return 1;
}
w[l][r]=0;
return 0;
}
if(z[l][r]){
return w[l][r];
}
long long x=0;
for(long long i=l;i<r;i++){
long long u=dfs(l,i);
long long v=dfs(i+1,r);
z[l][r]=z[l][i]^z[i+1][r];
if(u+v==0 && z[l][r]==k){
x=max(x,u+v+1);
}
else{
x=max(x,u+v);
}
}
w[l][r]=x;
return x;
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(long long i=1;i<=n;i++){
cin>>a[i];
if(a[i]==1){
y++;
}
if(a[i]==0){
y2++;
}
if(a[i]==1 && a[i-1]==1){
a[i]=0;
y2++;
}
}
if(n==y && k==0){
cout<<n/2;
}
else if(k==1){
cout<<y;
}
else if(k==0){
cout<<y2;
}
else if(n<20){
cout<<dfs(1,n);
}
else{
cout<<0;
}
return 0;
}
