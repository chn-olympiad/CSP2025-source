#include<bits/stdc++.h>
using namespace std;
long long maxn,pos,n,ans[6000005],a[5005],FAN;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int idx=0;
    stable_sort(a+1,a+n+1);
    ans[a[1]+a[2]]++;
    maxn=a[1]+a[2];
    for(int i=3;i<=n;i++)
    {
        for(int j=a[i]+1;j<=maxn;j++)
        {
            FAN=(FAN+ans[j])%998244353;
        }
        long long k=maxn;
        for(int j=k;j>=1;j--)
        {
            ans[j+a[i]]=(ans[j+a[i]]+ans[j])%998244353;
            maxn=max(j+a[i],maxn);
        }
        for(int j=1;j<=i-1;j++)
        {
            ans[a[i]+a[j]]++;
            ans[a[i]+a[j]]%=998244353;
        }
    }
    cout<<FAN%998244353;
    return 0;
}
