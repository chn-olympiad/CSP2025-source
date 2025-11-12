#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int a[15][15],b[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m*n;i++)
    {
        scanf("%d",&b[i]);
    }
    int p=b[1];
    sort(b+1,b+n*m+1,cmp);
    int pos=1;
    for (int i=1;i<=m;i++)
    {
        if (i%2==1)
        {
            for (int j=1;j<=n;j++)
            {
                a[i][j]=b[pos];
                pos++;
            }
        }
        else
        {
            for (int j=n;j>=1;j--)
            {
                a[i][j]=b[pos];
                pos++;
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (a[i][j]==p)
            {
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    return 0;
}
