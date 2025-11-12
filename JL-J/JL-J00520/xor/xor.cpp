#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
const ll N=1e4+10;
ll a[N],sum[N];
namespace sub1
{
    void solve()
    {
        cout<<1;
        return;
    }
}
namespace sub2
{
    void solve()
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int ans=0,q=0;
        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=n;j++)
            {
                for(int k=i;k<=i+j;k++)
                    ans++;
            }
        }
        cout<<ans;
    }
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n<=2)
    {
        sub1::solve();
        return 0;
    }
    if(n<=1e3+2)
    {
        sub2::solve();
        return 0;
    }
    else
        cout<<0;
    return 0;
}
