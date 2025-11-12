#include <bits/stdc++.h>

using namespace std;
int n,m,r,t;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n*m+1]={0};
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }

    t=a[1];
    sort(a+1,a+n*m+1,greater<int>() );
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==t)
        {
            r=i;
            break;
        }
    }
    int j=ceil(r*1.0/n);
    if(j%2==1)
    {
        cout<<j<<' ';
        if(n==2)
        {
            cout<<n-r%n;
        }
        else
            cout<<r%n;
    }
    else
    {
        cout<<j<<' ';
        if(n==2)
        {
            cout<<r%n+1;
        }
        else
            cout<<r%n;
    }
    return 0;
}
