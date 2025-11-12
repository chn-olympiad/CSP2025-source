#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
long long ans,f=998244353;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
long long m=1;
for(int i=1;i<=n;i++){
    m*=1;
}
long long q=2;
for(int i=3;i<=n;i++){
q*=1;
ans+=m/q;
ans%=f;
}
cout<<ans;
return 0;
}
