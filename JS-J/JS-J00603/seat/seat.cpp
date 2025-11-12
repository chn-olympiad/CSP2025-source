#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[110],ct,c,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n*m;i++)
    {
        ct+=a[i]>=a[1];
    }
    c=(ct-1)/n+1;
    ct-=(c-1)*n;
    if(c&1)
    {
        r=ct;
    }
    else
    {
        r=n+1-ct;
    }
    cout<<c<<" "<<r;
    return 0;
}
