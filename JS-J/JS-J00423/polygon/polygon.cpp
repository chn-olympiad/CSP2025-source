#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,dp[501][50010],a[5050],maxn=0,sum=0,s[501][50010],ans=0,as=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        as+=a[i];
    }
    sort(a+1,a+1+n);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        if(i>2){
            ans+=s[i-1][sum]-s[i-1][a[i]];
            ans%=mod;
        }
        sum+=a[i];
        for(int j=0;j<=sum;j++){
            if(j>=a[i])dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
            else dp[i][j]=dp[i-1][j];
        }
        s[i][0]=dp[i][0];
        for(int j=1;j<=as;j++){
            s[i][j]=s[i][j-1]+dp[i][j];
        }
    }
    cout << ans;
    return 0;
}
