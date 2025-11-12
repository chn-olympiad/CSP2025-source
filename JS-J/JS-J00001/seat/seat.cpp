#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,ans=1;
    cin>>n>>m;
    cin>>a;
    for(int i=2,x;i<=n*m;++i)
    {
        cin>>x;
        if(a<x)ans++;
    }
    int l=(ans+n-1)/n;
    cout<<l<<' ';
    if( l & 1 )
        cout<<(ans-1)%n+1;
    else
        cout<<n-(ans-1)%n;
    return 0;
}
/*
*/
