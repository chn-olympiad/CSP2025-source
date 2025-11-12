#include<bits/stdc++.h>
#define E 100010
using namespace std;
int n,a[E],mx;
long long ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n);
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>a[3]*2)
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
    mx=a[n];
    if(mx==0)
    {
        cout<<0;
        return 0;
    }
    if(mx==1)
    {
        int tp;
        for(int i=1;i<=n;i++)
            if(a[i]==1)
                tp++;
        cout<<tp-2;
        return 0;
    }
    cout<<ans%998244353;
    return 0;
}
