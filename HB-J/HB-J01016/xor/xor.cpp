#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,k,a[N],dp[N];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i =1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(dp[j]^a[j] == k)
            {
                dp[j] = max(dp[j],dp[j+1]+1);
            }
        }
    }
    cout << dp[n]+1;
    return 0;
}
