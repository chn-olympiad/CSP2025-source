#include<bits/stdc++.h>
using namespace std;
int a[1111111],sum[1111111],n,k,cnt,d[1111111],dp[1111111];
int fix(int a,int b){
    return a^b;
}
int fix2(int a,int b){
    int u=a,v=b,h=0;
    string s="";
    while(u!=0||v!=0){
       int r=u%2,l=v%2;
       s+=to_string(abs(r-l));
       u/=2,v/=2;
    }
    for(int i=s.size()-1;i>=0;i--){
        h=h*2+s[i]-48;
    }
    return h;
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
    sum[i]=fix(sum[i-1],a[i]);
}
for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
        if(fix2(sum[j],sum[i-1])==k){
            d[j]=max(d[j],i);
    }
  }
}
for(int i=1;i<=n;i++){
   for(int j=1;j<=i;j++){
        if(d[j]>=1){
    dp[i]=max(dp[i],dp[d[j]-1]+1);
        }
   }
   cnt=max(cnt,dp[i]);
}
cout<<cnt;
return 0;
}
