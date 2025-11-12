#include <bits/stdc++.h>

using namespace std;
int a[505],n,m;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;string x;cin>>x;
    long ans=1;
    for(long i=2;i<=n;i++){
        ans=(ans*i)%998244353;
    }cout<<ans;
    return 0;
}
