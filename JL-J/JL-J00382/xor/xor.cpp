#include <bits/stdc++.h>
using namespace std;
long long sum[1145140];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,maxn=-114514;
    cin >>n >>k;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin >>x;
        sum[i]=sum[i-1]^=x;
    }
    for(int i=1;i<=n;i++)
    {
        if()
    }
    cout <<maxn;
    return 0;
}
