#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5010,mod = 998244353;
int dp[2*N],p[2*N],a[N],pw[N],n,ans=0;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*2%mod;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=a[i];j++) dp[j]=pw[i-1];
        for(int j=a[i]+1;j<2*N;j++) dp[j]=p[j-a[i]];
        for(int j=0;j<2*N;j++) (p[j]+=dp[j])%=mod;
        (ans+=dp[2*a[i]+1])%=mod;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
