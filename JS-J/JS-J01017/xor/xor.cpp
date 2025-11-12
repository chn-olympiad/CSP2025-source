#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],pre[N],sum[N],dp[N],k;
map<int,int> m;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]^a[i];
    for(int i=1;i<=n;i++)
    {
        int t=sum[i]^k;
        if(a[i]==k)
            pre[i]=i;
        else
            if(m[t]||t==0)
                pre[i]=m[t]+1;
            else
                pre[i]=0;
        m[sum[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(pre[i])
            dp[i]=max(dp[i],dp[pre[i]-1]+1);
    }
    cout<<dp[n];
    return 0;
}
