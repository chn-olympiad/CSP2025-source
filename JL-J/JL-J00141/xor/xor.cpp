#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,dp[N],a[N],mp[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        int kl=a[i]^k;
        if(mp[kl]!=0 || kl==0)dp[i]=max(mx,dp[mp[kl]]+1);
        else dp[i]=mx;
        mp[a[i]]=i;
        mx=max(mx,dp[i]);
    }
    cout<<dp[n];
    return 0;
}
