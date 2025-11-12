#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=2e6+5;
int n,k;
int a[N],sum[N],dp[N],tag[M],nxt[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(nxt,-1,sizeof nxt);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=a[i]^sum[i-1];
        if(a[i]==k) nxt[i]=i-1;
        else if(tag[(k^sum[i])]) nxt[i]=tag[(k^sum[i])];
        else if(sum[i]==k) nxt[i]=0;
        tag[sum[i]]=i;
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(nxt[i]!=-1) dp[i]=max(dp[i],dp[nxt[i]]+1);
    }
    cout<<dp[n];
    return 0;
}