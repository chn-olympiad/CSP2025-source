#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,k,ans;
int a[N],f[N];
int dp[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        f[i]=(a[i]^f[i-1]);
    }
    for(int i=1; i<=n; i++)
    {
        dp[i]=dp[i-1];
        //cout<<dp[i]<<" ";
        for(int j=i-1; j>=0; j--)
        {
            if((f[i]^f[j])==k)
            {
                dp[i]=max(dp[i],dp[j]+1);
                //cout<<dp[i];
                break;
            }
            if(dp[j]+1<dp[i]) break;
        }
        //cout<<endl;
    }
    cout<<dp[n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
