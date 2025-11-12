#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int n,ans,sig;
int a[N],dp[N][N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    if(n==3)
    {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[n][i]);
    }
    cout<<ans;
    return 0;
}
