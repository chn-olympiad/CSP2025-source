#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[500005],pre[500005],a[500005],n,k;
map<ll,ll>m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    m[0]=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=a[i]^pre[i-1];
    }
    for(ll i=1;i<=n;i++){
        if(m.count(pre[i]^k))
            dp[i]=dp[m[pre[i]^k]]+1;
        dp[i]=max(dp[i],dp[i-1]);
        m[pre[i]]=i;
    }
    cout<<dp[n];
    return 0;
}
