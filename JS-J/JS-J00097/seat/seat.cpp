#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p,a[101],x=1,l,h;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>p;
    for(int i=2;i<n*m;i++)
    {
        cin>>a[i];
        if(a[i]>p)
            x++;
    }
    l=(x/(2*n))*2;
    if((x%(2*n))>0)
    {
        l++;
        if((x%(2*n))>n)
            l++;
    }
    if(l%2==1)
        h=x%(2*n);
    else
        h=2*n+1-(x%(2*n));
    cout<<l<<" "<<h<<'\n';
    return 0;
}
