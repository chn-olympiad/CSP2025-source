#include<bits/stdc++.h>
using namespace std;

int n,mod=998244353,a[5005];
long long ans;
int jc(int h)
{
    if(h==0)return 1;
    long long ans0;
    for(int i=1;i<=h;i++)
        ans0*=i;
    return ans0;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>2*a[3])
            cout<<1;
        else cout<<0;
        return 0;
    }
    for(int i=3;i<=n;i++)
    {
        ans+=(jc(n)/(jc(i)*jc(n-i)))%mod;
    }
    cout<<ans%mod;
    return 0;
}