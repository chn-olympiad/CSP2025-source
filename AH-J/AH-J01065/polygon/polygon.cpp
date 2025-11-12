#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[10];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    if(n==1)cout<<0;
    else if(n==2)
    {
        if(a[1]+a[2]>2*a[2])
        {
            cout<<1;
        }
        else cout<<0;
    }
    else
    {
        ll cnt=0;
        if(a[1]+a[2]>2*a[2])cnt++;
        if(a[2]+a[3]>2*a[3])cnt++;
        if(a[1]+a[3]>2*a[3])cnt++;
        if(a[1]+a[2]+a[3]>2*a[3])cnt++;
        cout<<cnt;
    }
    return 0;
}
