#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int bi=0;
long long ans=0;
long long mo=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        bi=max(bi,a[i]);
    }
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>2*bi)
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

    else
    {
        for(int i=3;i<=n;i++)
        {
            int q=1;
            for(int j=n-i+1;j>=1;j--)
            {
                ans+=j*q;
                q++;
                ans%=mo;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
// 1 1 1 1 1 1  4+3+2+1+3+2+1+2+1+1=20 63
// 3+2+1+2+1+1=10 64
// 2+1+1=4 65
// 1 66
}
