#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    int n,m,num=0,d=0,x=0,y=0;
    cin>>n>>m;
    int a[n*m+2+1],s[n+2+1][m+2+1];
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    d=a[1];
    sort(a+1,a+n*m+1);
    for (int i=n*m;i>=1;i--)
    {
        if (a[i]==d)
        {
            break;
        }
        num++;
    }
    if (num%n==0)
    {
        if (num/n%2==0)
        {
            x=num/n;
            y=1;
        }
        else
        {
            x=num/n;
            y=n;
        }
    }
    else
    {
        if ((num/n+1)%2==0)
        {
            x=num/n+1;
            y=n-num%n+1;
        }
        else
        {
            x=num/n+1;
            y=num%n;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
