#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[100010];
int ans(int n){
int a=rand();
return a%mod;
}
int main(){
//freopen("polygon.in","r",stdin);
//freopen("polygon.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
cout<<ans(n)<<endl;
return 0;
}
