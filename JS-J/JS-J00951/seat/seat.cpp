#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int f=a[1];
    sort(a+1,a+1+n*m);
    int x=1,y=1;
    for (int i=n*m;i>=1;i--)
    {
        if (a[i]==f)
        {
            cout<<y<<' '<<x<<endl;
            break;
        }
        if (y%2==1)
        {
            x++;
            if (x==n+1)
            {
                x=n;
                y++;
            }
        }
        else
        {
            x--;
            if (x==0)
            {
                x=1;
                y++;
            }
        }
    }
    return 0;
}
