#include<bits/stdc++.h> 
using namespace std;
int a[5001],n,m=3;
int main(){
freopen("polygon.in","r",stdin);	
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=1;i<=n;i++)
m=m*a[i]/n+1;
cout<<m%998244353;
fclose(stdin);
fclose(stdout);
return 0;



}
