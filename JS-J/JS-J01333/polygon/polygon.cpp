#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5005;
const int mod=998244353;
int a[MAXN],dp[2][MAXN*MAXN];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f=0;
    }
    if(f){
        int ans=0;
        for(int i=3;i<=n;i++){
            int temp=1;
            int k=2;
            for(int j=i+1;j<=n;j++){
                int t=j;
                if(j%k==0&&k<=n-i)t/=k++;
                temp=temp*t%mod;
            }
            ans=(ans+temp)%mod;
        }
        cout<<ans;
    }
    else{
        sort(a+1,a+1+n);
        int pre=a[1]+a[2];
        for(int i=3;i<=n;i++){
            pre=pre+a[i];
            for(int j=3;j<=pre;j++){
                dp[i&1][j]=dp[(i+1)&1][j];
                if(a[i]*2<j)dp[i&1][j]=max(dp[i&1][j],(dp[(i+1)&1][j-a[i]]+1)%mod);
            }
        }
        int ans=0;
        for(int i=1;i<=pre;i++)cout<<dp[n&1][i]<<" ";
        for(int i=1;i<=pre;i++)ans=(ans+dp[n&1][i])%mod;
        cout<<ans;
    }
    return 0;
}
