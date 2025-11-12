#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],k,d=0,b[15][15]={};
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    k=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    for(int x=1;x<=m;x++)
    {
        if(x%2==1)
        {
            for(int i=1;i<=n;i++)
            {
                b[i][x]=a[++d];
            }
        }
        else
        {
            for(int i=n;i>=1;i--)
            {
                b[i][x]=a[++d];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i][j]==k)
            {
                cout << j << " " << i << endl;
                break;
            }
        }
    }
    return 0;
}
