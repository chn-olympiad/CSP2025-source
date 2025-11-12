#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int N=5e5+5;
int n,k,dp[N],a[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(a[i]==k)dp[i]++;
        else
        {
            int x=a[i],y=i-1;
            while(x!=k&&y>0)
            {
                x=(x^a[y]);
                y--;
            }
            if(x!=k)continue;
            dp[i]=max(dp[i],dp[y]+1);
        }
    }
    cout<<dp[n];
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
}
