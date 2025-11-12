#include<bits/stdc++.h>
using namespace std;
int a[5001],dp[5001];
int n;
bool b=true;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=1)
        {
            b=false;
            break;
        }
    }
    if(b==true)
    {
        int t=0,s=0;
        dp[n-2]=1
        for(int i=n-3;i>=1;i--)
            dp[i]+=dp[i+1];
        t+=dp[1];
        for(int i=t;i>=1;i--)
        {
            s+=i;
        }
        cout<<s%998244353;
    }
    return 0;
}
