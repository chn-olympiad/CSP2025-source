#include<bits/stdc++.h>
using namespace std;

int n,m,a[15][15],pm=1,c,r;

int main()
{

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]>a[1][1])pm++;
        }
    }
    if(pm%n==0)c=pm/n;
    else c=pm/n+1;
    if(c%2!=0)
    {
        r=pm-n*(c-1);
    }
    else r=n-pm-n*(c-1)+1;
    cout<<c<<" "<<abs(r);
    return 0;
}
