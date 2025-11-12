#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m,ans=1;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
        ans=ans%998244353;
    }
    cout << ans;
    return 0;
}
