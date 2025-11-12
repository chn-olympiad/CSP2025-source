#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,cj;
int pm;
cin>>n>>m;
int a[n*m+1];
for(int i=0;i<n*m;i++)
{
    cin>>a[i];
}
cj=a[0];
for(int i=0;i<n*m-1;i++)
for(int j=i;j<n*m;j++)
if(a[j]>a[i])
swap(a[i],a[j]);
for(int i=0;i<n*m;i++)
if(a[i]==cj){
    pm=i+1;
    break;
}
double k=pm;
int l=ceil(k/n);
cout<<ceil(k/n)<<" ";
if(l%2==1)
{
    if(pm%n==0)
    cout<<n;
    else
    cout<<pm%n;
}
else
{
    if(pm%n==0)
    cout<<1;
    else
    cout<<n-pm%n+1;
}
return 0;
}
