#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,ans=0;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        long long n,a[100001],b[100001],c[100001];
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
        }
        for(int j=1;j<=n;j++)
        {
            long long d;
            d=max(a[i],max(b[i],c[i]));
            ans+=d;
        }
        for(int j=1;j<=n;j++)
        {

        }
    }
    cout<<ans;
    return 0;
}
