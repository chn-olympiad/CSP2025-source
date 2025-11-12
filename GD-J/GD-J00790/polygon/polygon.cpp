#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long s1 = 1;
long long s2 = 1;
long long s3 = 1;
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin>>n;
    for(int i = 3; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            s1 *= j;
        }
        for(int j = 1; j <= i; j++)
        {
            s2 *= j;
        }
        for(int j = 1; j <= n - i; j++)
        {
            s3 *= j;
        }
        ans += s1 / s2 / s3;
        ans %= 998244353;
    }
    cout<<ans<<endl;
    return 0;
}
