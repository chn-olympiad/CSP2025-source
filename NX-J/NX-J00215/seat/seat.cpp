#include<bits/stdc++.h>
using namespace std;
int num[100];
bool cmp(int x, int y)
{
    return (x > y);
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    int fd;
    scanf("%d", &fd);
    num[1] = fd;
    for(int i = 2; i <= n * m; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num +1, num+n*m +1, cmp);
    for(int i = 1; i <= n * m; i++)
    {
        if(num[i] == fd)
        {
            int c, r;
            if(i % n == 0) c = i / n;
            else c = i / n +1;

            if(c % 2 == 0) r = n - (i % n) + 1;
            else r = i % n;
            printf("%d %d", c, r);
            break;
        }
    }
    return 0;
}
