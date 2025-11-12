#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
   cin>>a[i];
   sort(a+1,a+1+n);
   if(n<=2) cout<<0;
      else if(n==3&&a[2]<a[1]+a[0]+a[2]) cout<<1;
return 0;}
