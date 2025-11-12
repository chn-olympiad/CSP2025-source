#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,t=0,p=0,q=0;
cin>>n>>m;
int a[1000];
for (int i=1;i<=m*n;i++)
cin>>a[i];
int k=a[1];
for (int i=1;i<=n*m;i++)
for (int j=i;j<=n*m;j++)
if (a[j]<a[j+1])
swap(a[j],a[j+1]);
for (int i=1;i<=n*m;i++)
    if (a[i]==k)
    t=i;
int s=t/n;
if (t%n==0){
    p=t/n;
    q=n;
    cout<<p<<' '<<q;
    return 0;}
else if (t%n<=n){
    p=t/n+1;
    q=n-(t-s*n);
    cout<<p<<' '<<q;
    return 0;}
else if (t%n>n){
    p=t/n+1;
    q=t-s*n;
    cout<<p<<' '<<q;
    return 0;}
return 0;}
