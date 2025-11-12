#include<bits/stdc++.h>
using namespace std;
long long cmp(long x,long y){
long long sum=1,sun=1;
for(long long i=x-y+1;i<=x;i++){
sum*=i;
sum=sum%998244353;
}
for(long long j=1;j<=y;j++){
sun*=j;
sun=sun%998244353;
}
return sum/sun;
} 
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
long long n,ans=0,s;
cin>>n;
int a[n+5],b[1000005][1000005];
for(int i=1;i<=n;i++){
cin>>a[i];
}
sort(a+1,a+1+n);
if(n==3){
if(a[1]+a[2]>a[3])cout<<"1";
else cout<<"0";
}else if(a[n]==1){
for(int i=3;i<=n;i++){
ans+=(cmp(n,i))%998244353;
}
cout<<ans;
} else cout<<"0";
return 0;
}

