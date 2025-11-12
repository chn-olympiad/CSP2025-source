#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[500011];
ll dp[500011];
ll m;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            m=a[j];
            for(int l=j+1;l<=i;l++)
            {
                m^=a[l];
            }
            if(m==k)
            {
                dp[i]=max(dp[i],dp[j-1]+1);

            }

        }
        if(dp[i]==0)
        {
            dp[i]=dp[i-1];
        }
        //cout<<dp[i]<<"\n";
    }
    cout<<dp[n];
    return 0;
}
