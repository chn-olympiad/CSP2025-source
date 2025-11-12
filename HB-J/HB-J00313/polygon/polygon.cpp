#include<bits/stdc++.h>
#define ll long long
#include<cmath>
using namespace std;
long long n,a[6000],b[6000],ans,sum;
void solve()
{
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
        std::cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    if(a[5]<=10)
    {
        ans=a[5]*a[5]-a[4]*a[4];
    }
    if(a[5]>=10)
    {
        sum=a[5]*a[5]-a[4]*a[4];
        for(int i=1;i<=500;i++)
        {
            if(i*i==sum)
                ans=i;
        }
    }
    cout<<ans<<endl;
}
int  main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    solve();
    return 0;
}
