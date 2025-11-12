#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll x,ll y)
{
    if(x>y) return true;
    return false;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll m,n,R,M;
    cin>>m>>n;
    ll a[m*n];
    for(ll i=1;i<=n*m+1;i++)
    {
        cin>>a[i];
    }
    R=a[1];
    for(ll i=1;i<=n*m;i++)
    {
        if(R=a[i]) M=i;
    }
    cout<<M<<' '<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
