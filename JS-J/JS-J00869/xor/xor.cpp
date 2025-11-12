#include <bits/stdc++.h>
using namespace std;
long long a[500010],n,k,dp[500010],sum,cnt;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin >> n >> k;
for(int i=1;i<=n;i++){
    cin >> a[i];
}
for(int i=1;i<=n;i++){
sum=0;
for(int j=i;j<=n;j++){
    sum=sum xor a[j];
    if(sum==k){
        sum=0;
        dp[j]=max(dp[j],dp[j-1]+1);
    }
    dp[j]=max(dp[j],dp[j-1]);
    cnt=max(dp[j],cnt);
}
}
cout << cnt;
return 0;
}
