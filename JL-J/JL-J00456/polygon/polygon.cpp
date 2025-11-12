#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxx,cnt;
long long ans=1;
int main()
{
    freopen("polygon.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    freopen("polygon.out","w",stdout);
    if(maxx==1)
    {
        for(int i=1;i<n;i++)
        {
            ans=(ans*2)%998244353;
        }
        ans=(ans*2-1-n-n*(n-1)/2)%998244353;
        cout<<ans;
    }
    else if(n==3)
    {
        if(a[1]+a[2]+a[3]>2*maxx) cout<<"1";
        else cout<<"0";
    }
}
