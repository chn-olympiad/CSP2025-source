#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,k,a[500005],ans;
map<ll,ll>b;
ll dp[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin >> n >> k;
    for(int i=1;i<=n;i++)cin >> a[i];
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum=sum^a[i];
        ll now=sum^k;

        if(sum==k){
            dp[i]=max(dp[i-1],dp[b[0]]+1);
        }else{
            if(b[now])dp[i]=max(dp[i-1],dp[b[now]]+1);
            else dp[i]=dp[i-1];
        }

        b[sum]=i;
        ans=max(ans,dp[i]);
    }
    cout << dp[n];




    return 0;
}
