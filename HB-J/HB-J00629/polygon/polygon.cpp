#include<bits/stdc++.h>
using namespace std;
long long n,a[5141],s,g,p,q;
void dfs(long long k,long long mx,long long t)
{
    if(t>2*mx)s=(s+1)%998244353;
    for(long long i=k+1;i<=n;i++)dfs(i,max(a[i],mx),t+a[i]);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>a[i];
    if(n<=3)
    {
        if(a[1]+a[2]>a[3]||a[1]+a[3]>a[2]||a[2]+a[3]>a[1])cout<<1;
        else cout<<0;
        return 0;
    }
    if(n<=11)
    {
        dfs(0,0,0);
        cout<<s%998244353;
        return 0;
    }
    for(long long i=2;i<=n;i++)g=(g*i)%998244353;
    for(long long i=3;i<=n;i++)
    {
        for(long long j=2;j<=i;i++)p=(p*j)%998244353;
        for(long long j=2;j<=n-i;i++)q=(q*j)%998244353;
        p=p*q%998244353;
        s+=g/q%998244353;
    }
    cout<<s;
    return 0;
}
