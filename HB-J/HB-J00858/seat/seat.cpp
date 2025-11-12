#include <bits/stdc++.h>
using namespace std;
int a[105][105],R;
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,c,r;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    R=a[1][1];
    c=1;
    r=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (R<a[i+1][j])
            {
                R=a[i+1][j];
                c=j;
                r=i+1;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
