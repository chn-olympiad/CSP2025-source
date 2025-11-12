#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005],maxa=-1,sum;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            maxa=max(a[i],maxa);
            sum+=a[i];
        }
        if(sum>2*maxa) cout<<1%mod;
        else cout<<0%mod;
    }
    return 0;
}
