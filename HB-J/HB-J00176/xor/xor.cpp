#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k;
ll a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    int flag=1, flg=1;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
            flag=0;
        if(a[i]!=0 && a[i]!=1)
            flg=0;
    }
    if(flag && k==0)
        cout<<n/2;
    else if(flg && (k==0 || k==1))
    {
		ll cnt=0;
        for(ll i=1;i<=n;i++)
            if(a[i]==k)
                cnt++;
        cout<<cnt;
    }
    return 0;
}
