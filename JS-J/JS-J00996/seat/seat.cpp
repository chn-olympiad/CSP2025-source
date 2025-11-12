#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(int x, int y)
{
    return x > y;
}

int n, m, sx, pos;
int c, r;
int s[105];

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d %d",&n, &m);
    int l = n * m;
    scanf("%d",&s[1]);
    sx = s[1];
    for (int i = 2;i <= l;i++)
        scanf("%d",&s[i]);
    sort(s + 1, s + l + 1, cmp);
    for (int i = 1;i <= l;i++)
        if (s[i] == sx)
        {
            pos = i;
            break;
        }
    c = ceil(1.0 * pos / n);
    if (c % 2 == 1)
    {
        for (int i = 1;i <= n;i++)
            if (s[i + n * (c - 1)] == sx)
            {
                r = i;
                break;
            }
    }
    else
    {
        for (int i = 1;i <= n;i++)
            if (s[i + n * (c - 1)] == sx)
            {
                r = n - i + 1;
                break;
            }
    }
    printf("%d %d \n",c, r);
    return 0;
}
