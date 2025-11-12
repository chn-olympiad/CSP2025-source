#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;
ll dp[505][505][505];
int a[5005];
ll q[5005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    for(int i=3;i<=n;i++){
        for(int j=3;j<=i;j++){
            dp[i][j][0]=dp[i-1][j][0];
            for(int k=1;k<=5000;k++){
                if(2*a[i]<k&&dp[i][j][k]){
                    dp[i][j][k+a[i]]++;
                    dp[i][j][0]++;
                }
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[n][i][0];
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}