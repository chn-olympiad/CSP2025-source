#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,q,b[111];
    int n,m,g,r,f=1;
    g = 1;
    cin>>n>>m;
    int c = n+m;
    for(int i = 1;i<c;i++)
    {
        cin>>b[i];
        if(b[1]<b[i])g++;
    }
    for(int j = 1;j<m;j++)
    {
        if(g<n)
        {
            r+=g;
            f = 1;
        }
        else if(g -= n>n)
        {
        f++;
        r = g-n+1;
        }
    }
    cout<<r<<' '<<f;
    return 0;
}
