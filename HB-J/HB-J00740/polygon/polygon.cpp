#include <bits/stdc++.h>
using namespace std;
const int mod =998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005];
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    stable_sort(&a[1],&a[n+1]);
    cout<<(a[n]%2?n+a[n]-a[1]:n+a[n]-a[n-1]-1)%mod;
    return 0;
}
