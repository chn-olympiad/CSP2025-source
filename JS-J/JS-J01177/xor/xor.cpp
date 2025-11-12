#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500009];
int he[500009];
int lasp[10000009];
int dp[500009];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        he[i]=he[i-1]^a[i];
    }
    memset(lasp,-1,sizeof(lasp));
    lasp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(lasp[he[i]^k]!=-1)
        {
            dp[i]=max(dp[i],dp[lasp[he[i]^k]]+1);
        }
        lasp[he[i]]=i;
    }

    cout<<dp[n];
    return 0;
}
