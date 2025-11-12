#include<iostream>
#include<cstdio>
#include<map>
#include<set>
using namespace std;

long long n,k,a[500005],sum[500005],pos[500005];
long long dp[500005];
map<long long,long long> m;
set<long long> s;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
        long long x=s.count(k^sum[i]);
        if(x || sum[i]==k)
        {
            pos[i]=m[k^sum[i]]+1;
        }
        else
        {
            pos[i]=-1;
        }
        s.insert(sum[i]);
        m[sum[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(~pos[i])
        {
            dp[i]=max(dp[i],dp[pos[i]-1]+1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
