#include<bits/stdc++.h>
using namespace std;
long long int n,a[5005],MOD=998244353,tot=0;
long long fact_123(long long int x)
{
    long long ans = 1;
    for(int i = 2;i<=x;i++)
    {
        ans=(ans*i)%MOD;
    }
    return ans;
}
long long qs_123(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%MOD;
        }
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
            cout << 1;
        else
            cout << 0;
        return 0;
    }
    if(n>=1)
    {
        for(int i = 3;i<=n;i++)
        {
            tot=(tot+((fact_123(n)*qs_123(fact_123(i),MOD-2)%MOD)*qs_123(fact_123(n-i),MOD-2))%MOD)%MOD;
        }
    }
    cout << tot;
    return 0;
}
