#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m,t;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    if(n==1)
    {
        for(int i=1;i<=m;i++)
        {
            cin>>a[i];
        }
        t=a[1];
        sort(a+1,a+m+1,greater<int>() );
        for(int i=1;i<=m;i++)
        {
            if(a[i]==t)
            {
                cout<<1<<" "<<i;
            }
        }
    }
    else if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        t=a[1];
        sort(a+1,a+n+1,greater<int>() );
        for(int i=1;i<=n;i++)
        {
            if(a[i]==t)
            {
                cout<<i<<" "<<1;
            }
        }
    }
    else if(n==2)
    {
        for(int i=1;i<=2*m;i++)
        {
            cin>>a[i];
        }
        t=a[1];
        sort(a+1,a+n+1,greater<int>() );
        for(int i=1;i<=2*m;i++)
        {
            if(a[i]==t&&(i<2||i==2))
            {
                cout<<1<<" "<<i;
            }
            if(a[i]==t&&i>2)
            {
                cout<<2<<" "<<2*m-i;
            }
        }
    }
    return 0;
}
