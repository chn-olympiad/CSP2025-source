#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,l,x;
int g[400];
int main()
{
    #if 1
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    #endif
    cin>>n>>m;
    l=n*m;
    for(int i=1;i<=l;i++)
    {
        cin>>g[i];
        if(g[i]>=g[1]) x++;
    }
    c=x/n+bool(x%n);
    r=x%n;if(r==0) r=n;
    if(c%2==0)
    {
        r=n-r+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
