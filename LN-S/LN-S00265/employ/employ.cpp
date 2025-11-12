#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
int ans=1;
signed main()
{
    int n,m;
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        ans*=n;
        ans%=mod;
    }
    cout<<ans;

    return 0;
}
