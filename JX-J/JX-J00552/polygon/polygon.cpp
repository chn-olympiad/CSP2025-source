#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5005],sum;
const int mod=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n==1||n==2)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)sum+=a[i];
    if(sum>2*a[n])
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
