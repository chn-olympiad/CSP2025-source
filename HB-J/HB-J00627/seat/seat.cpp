#include <bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r;
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int b=a[1];
    for (int i=1;i<=n*m;i++)
    {
        for (int j=1;j<=i;j++)
        {
            if (a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    for (int i=1;i<=n*m;i++)
    {
        if (b==a[i])
        {
            c=(i-1)/n+1;
            if (c%2==0)
            {
                r=n-(i%n)+1;
            }
            else
            {
                r=i%n;
            }
            break;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
