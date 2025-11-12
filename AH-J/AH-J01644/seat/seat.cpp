#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],f,t;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    f=a[1];
    sort(a+1,a+n*m);
    for (int i=1;i<=n*m;i++)
    {
        if (f==a[i])
        {
            t=n*m-i;
            break;
        }
    }
    int count=0;
    for (int i=1;i<=m;i++)
    {
        if (i%2==1)
        {
            for (int j=1;j<=n;j++)
            {
                count++;
                if (t==count)
                {
                    cout<<i<<' '<<j;
                    break;
                }
            }
        }
        else
        {
            for (int j=n;j>=1;j--)
            {
                count++;
                if (t==count)
                {
                    cout<<i<<' '<<j;
                    break;
                }
            }
        }
    }

    return 0;
}
