#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
long long n,k,ans=0;
cin>>n>>k;
int a[n+5];
for(int i=1;i<=n;i++)cin>>a[i];
if(k==1){
for(int i=1;i<=n;i++){
if(a[i]==1)ans++;
}
}if(k==0){
for(int i=1;i<=n;i++){
if(a[i]==0)ans++;
if(a[i]==1&&a[i+1]==1)ans++;
}
}
cout<<ans;
return 0;
}

