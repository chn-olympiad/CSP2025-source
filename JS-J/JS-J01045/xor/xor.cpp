#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500000+7];
int sum[500000+7];
int dp[5000000+7];
int xorr(int a,int b)
{
    return sum[a]^sum[b];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i)sum[i]=sum[i-1]^a[i];
        else sum[i]=a[i];
    }
    dp[0]=bool(a[0]==k);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)dp[i]=max(dp[i],dp[j]+bool(xorr(j,i)==k));
        dp[i]=max(dp[i],0ll+bool(sum[i]==k));
    }
    cout<<dp[n-1];
    return 0;
}
