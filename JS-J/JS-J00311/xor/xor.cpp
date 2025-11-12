#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000008],dp[1000008];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sum=0,now;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        a[i]=a[i-1]^a[i];
    }
    a[0]=0;
    for(int i=0;i<n;i)
    {
        for(int j=i+1;j<=n;j++)
        {
            if((a[i]^a[j])==k)
            {
                sum++;
                i=j;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}
