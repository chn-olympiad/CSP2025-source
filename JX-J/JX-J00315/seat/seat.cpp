#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int dp[1005],w[1005],v[1005],m;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
for(int i=1;i<=10;i++){
    w[i]=i;
    cin>>v[i];
}
cin>>m;
for(int i=w[1];i<=m;i++)
    dp[i]=v[1]*i;
for(int i=2;i<=10;i++)
    for(int j=w[i];j<=m;j++)
    dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
cout<<dp[m]<<endl;
return 0;
}
