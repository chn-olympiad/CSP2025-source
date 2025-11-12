#include<bits/stdc++.h>
#define ll long long;
using namespace std;
const int N=1e5+5;
int t,a[N],b[N],c[N],d[N],A,B,C,ans[N];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
ll n;
cin>>t;
for(int p=1;p<=t;p++){
cin>>n;
for(int i=0;i<n;i++){
cin>>a[i]>>b[i]>>c[i];
if(a[i]>b[i]&&a[i]>c[i]){
d[i]=1;
A++;
}
else if(b[i]>a[i]&&b[i]>c[i]){
d[i]=2;
B++;
}
else if(c[i]>b[i]&&c[i]>a[i]){
d[i]=3;
C++;
}
if(A>n/2&&i=n-1||B>n/2&&i=n-1||C>n/2&&i=n-1){
if(d[i]==1){
a[i]=0;
}
if(d[i]==2){
b[i]=0;
}
else if(d[i]==3){
c[i]=0;
}
i=0;
}
else if(A<=n/2&&i=n-1||B<=n/2&&i=n-1||C<=n/2&&i=n-1){
if(d[i]==1){
ans[p]+=a[i];
}
if(d[i]==2){
ans[p]+=b[i];
}
else if(d[i]==3){
ans[p]+=c[i];
}
}
}
}
for(int r=1;r<=t;r++){
cout<<ans[r]<<endl;
}
return 0;
}
