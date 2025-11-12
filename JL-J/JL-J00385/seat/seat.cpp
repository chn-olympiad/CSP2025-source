#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[105];
int a_1[15][15];
int R;

bool cmp (int a, int b)
{
    return a > b;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n*m; i++)
        scanf("%d",&a[i]);
    R = a[1];
    sort(a+1, a+n*m+1, cmp);
    int i = 1, j = 1, cnt = 1;
    while (true)
    {
        a_1[i][j] = a[cnt];
        if (a_1[i][j] == R)
        {
            printf("%d %d", j, i);
            return 0;
        }
        if (i == n && j % 2 == 1)
            j++;
        else if (i == 1 && j % 2 == 0)
            j++;
        else if (i != n && j % 2 == 1)
            i++;
        else if (i != 1 && j % 2 == 0)
            i--;
        cnt++;
    }
    return 0;
}
