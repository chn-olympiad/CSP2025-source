#include<bits/stdc++.h>
#define ll long long
using namespace std;
int maxn=100005;
int mod=998244353;
int a[5005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=3;i--)
    {
        ll c=1;
        for(int j=n;j>n-i;j--)
        {
            c*=j;
            c%=mod;
        }
        for(int j=1;j<=i;j++)
        {
            c/=j;
        }
        ans+=c;
    }
    cout<<ans<<endl;
    return 0;
}
