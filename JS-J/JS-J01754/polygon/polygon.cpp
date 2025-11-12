#include<iostream>
#include<cstdio>
using namespace std;

const long long mod=998244353;
long long n,a[5005];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long ans=0;
    for(int i=1;i<(1<<n);i++)
    {
        long long sum=0,maxx=0,cnt=0;
        for(int j=0;j<n;j++)
        {
            if(i>>j&1)
            {
                sum+=a[j+1];
                maxx=max(maxx,a[j+1]);
                cnt++;
            }
        }
        if(cnt>=3 && sum>maxx*2)
        {
            ans=(ans+1)%mod;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
