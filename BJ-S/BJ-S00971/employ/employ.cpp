#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long f3(int n)  {
    long long ans = 1;
    long long a[n];
    a[0] = 1,a[1] = 1;
    for (int i = 2; i <= n; i++)    {
        a[i] = ((a[i - 1] % mod) * i) % mod;
    }
    ans = a[n] % mod;
    return ans;
}
signed main()   {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin>>n;
    cout<<f3(n)<<endl;
    return 0;
}