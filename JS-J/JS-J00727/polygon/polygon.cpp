#include <bits/stdc++.h>
using namespace std;
int a[50005];
vector<long long>v;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) f=1;
    }
    sort(a+1,a+n+1);
    if(f==0)
    {
        long long d=n*(n-1),ans=0;
        for(int i=3;i<=n;i++)
        {
            d=d%998244353*(n-i+1)%998244353;
            ans=(ans+d)%998244353;
        }
        cout<<ans;
    }
    else
    {
        long long an=0;
        v.push_back(a[1]);
        v.push_back(a[2]);
        v.push_back(a[1]+a[2]);
        for(int i=3;i<=n;i++)
        {
            long long len=v.size();
            for(int j=0;j<len;j++)
            {
                if(v[j]>a[i])
                {
                    //cout<<v[j]<<" "<<a[i]<<'\n';
                    an=(an+1)%998244353;
                }
                v.push_back(a[i]+v[j]);
            }
            v.push_back(a[i]);
        }
        cout<<an;
    }
    return 0;
}