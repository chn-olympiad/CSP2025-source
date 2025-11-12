#include <bits/stdc++.h>
using namespace std;
long long n;
long long milthm[5001];
const int mod=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>milthm[i];
    }
    if(n==3)
    {
        if(milthm[1]+milthm[2]>milthm[3]&&milthm[3]+milthm[2]>milthm[1]&&milthm[1]+milthm[3]>milthm[2])
        {
            cout<<1%mod;
            return 0;
        }
        else
        {
            cout<<0%mod;
            return 0;
        }
    }
    return 0;
}

