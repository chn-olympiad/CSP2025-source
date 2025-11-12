#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    long long ans=0;
    for(int i=m;i<=n;i++)
    {
        long long ans1=1;
        for(int j=m-1;j>=0;j--)
        {
            ans1*=(n-j);
            ans1%=998244353;
        }
        ans+=ans1;
    }
    cout << ans%998244353;
    return 0;
}
