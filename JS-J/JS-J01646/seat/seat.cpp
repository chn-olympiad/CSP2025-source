#include<bits/stdc++.h>
using namespace std;
int n,m,b,j=1,a,l,ll;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    for(int i = 2;i <= m*n;i++)
    {
        cin>>b;
        if(b>a) j++;
    }
    l=j%n;
    if(l==0)
    {
        ll=j/n;
    }
    else
    {
        ll=j/n+1;
    }
    cout<<ll<<' ';
    if(ll%2==0)
    {
        cout<<n-l+1;
    }
    else
    {
        if(l==0) l=n;
        cout<<l;
    }
    return 0;
}
