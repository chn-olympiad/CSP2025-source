#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[15][15];
    int t=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;i<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    if(a[1][1]==1)
    {
        if(m%2==1)
        {
            cout<<m<<" "<<n;
        }
        else
        {
            cout<<m<<" "<<1;
        }
        return 0;
    }
    if(a[1][1]==n*m)
    {
        cout<<1<<" "<<1;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[1][1]<a[i][j])
            {
                t++;
            }
        }
    }
    if(t<n)
    {
        cout<<1<<" "<<t;
    }
    else
    {
        if(t%n==0)
        {
            if((t/n)%2==0)
            {
                cout<<t/n<<" "<<1;
            }
            else
            {
                cout<<t/n<<" "<<n;
            }
        }
        else
        {
            if((t/n+1)%2==0)
            {
                cout<<t/n+1<<" "n-(t%n);
            }
            else
            {
                cout<<t/n+1<<" "t%n;
            }
        }
    }
    return 0;
}
