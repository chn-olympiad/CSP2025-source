#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[105],b[11][11];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int s=a[1],h=1;
    sort(a+1,a+n*m+1,cmp);
    for (int i=1;i<=m;i++)
    {
        if (i%2==1)
        {
            for (int j=1;j<=n;j++)
            {
                b[j][i]=a[h];
                h++;
            }
        }
        if (i%2==0)
        {
            for (int j=n;j>=1;j--)
            {
                b[j][i]=a[h];
                h++;
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (b[i][j]==s)
            {
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
