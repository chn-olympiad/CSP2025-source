#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int a[10005],n;
long long ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=3)
    {
        if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    ans=1;
    for(int i=2;i<=n-2;i++)
    {
        int t=n;
        long long cnt=1;
        for(int j=1;j<=i-1;j++)
        {
            cnt=cnt*t%Mod;
            t--;
        }
        cnt/=(i-1);
        ans=(ans+cnt)%Mod;

    }
    cout<<ans%Mod;
    return 0;
}
