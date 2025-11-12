#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[25000005];
int a[5005];
int n;
const int mod=998244353;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int maxn=0,ans=0;
    dp[0]=1;
    for(int i=1; i<=n; i++){
        maxn+=a[i];
        for(int j=maxn; j>=1; j--){
            if(j>=a[i]){
                dp[j]+=dp[j-a[i]];
                if(j>2*a[i]) ans+=dp[j-a[i]];
                ans%=mod;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
