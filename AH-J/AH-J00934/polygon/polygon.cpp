#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
long long ans;
const int mod=998244353;
int a[5005];
int f[5005][5005];
int pw2(int x)
{
    if(x==0) return 1;
    long long tmp=pw2(x/2);
    return tmp*tmp*(x%2==0?1:2)%mod;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=0;i<=n;i++) f[i][0]=pw2(i);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5003;j++)
        {
            f[i][j]=(f[i-1][j]+f[i-1][max(j-a[i],0)])%mod;
        }
        if(i<n)
            ans=(ans+f[i][a[i+1]+1])%mod;
    }
    cout<<ans;
    return 0;
}

