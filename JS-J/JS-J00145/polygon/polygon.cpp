#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int n;
int dp[5005];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>dp[i];
    }
    if(n==3)
    {
        int q=max(dp[1],dp[2]);
        q=max(q,dp[3]);
        if(dp[1]+dp[2]+dp[3]>2*q)
        {
            cout<<1<<endl;
            return 0;
        }
        else
        {
            cout<<0<<endl;
            return 0;
        }
    }
    else{
        cout<<(2+n)*(n-2)/2<<endl;
    }
    return 0;
}
