#include <bits/stdc++.h>
using namespace std;

int a[105];
int s[15][15];

bool cmp(int x,int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    scanf("%d %d",&n,&m);

    for(int i = 1;i <= n*m;i++)
    {
        scanf("%d",&a[i]);
    }

    int p = a[1];

    sort(a+1,a+n*m+1,cmp);

    int k = 1;
    for(int i = 1;i <= m;i++)
    {
        if(i % 2 == 1)
        {
            for(int j = 1;j <= n;j++)
            {
                s[j][i] = a[k++];
            }
        }
        else
        {
            for(int j = n;j >= 1;j--)
            {
                s[j][i] = a[k++];
            }
        }
    }

    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(s[i][j] == p)
            {
                printf("%d %d",j,i);
                return 0;
            }
        }
    }

    return 0;
}
