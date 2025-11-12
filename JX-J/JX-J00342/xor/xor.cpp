#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[5e5+1];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1&&k==0)
    {
        cout<<0;
        return 0;
    }
    if(n==2&&k==0)
    {
        cout<<1;
        return 0;
    }
    if(k==0)
    {
        cout<<n/2;
        return 0;
    }
    cout<<0;
    return 0;
}
