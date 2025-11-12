#include <bits/stdc++.h>
using namespace std;
long long p[500005],n,k,x;
int f[500005],ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        p[i]=p[i-1]^x;

    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            f[i]=max(f[i],f[i-j]+((p[i]^p[i-j])==k));
        }
    }
    for(int i=1;i<=n;++i)
        ans=max(ans,f[i]);
    cout<<ans;
    return 0;
}
