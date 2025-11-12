#include <bits/stdc++.h>
using namespace std;

int t;

struct Node
{
    short c1, c2, c3;
    void read()
    {
        cin >> c1 >> c2 >> c3;
    }
}a[100005];


bool cmp1(Node x, Node y)
{
    return min(x.c1-x.c2, x.c1-x.c3) > min(y.c1-y.c2, y.c1-y.c3);
}
bool cmp2(Node x, Node y)
{
    return x.c2-x.c3 > y.c2-y.c3;
}
bool cmp3(Node x, Node y)
{
    return x.c3 > y.c3;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        int n, i, ans = 0, m1 = 0, m2 = 0, m3 = 0;
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
        {
            a[i].read();
        }
        sort(a+1, a+n+1, cmp1);
        for(i = 1; i <= n && m1 < n/2 && min(a[i].c1-a[i].c2, a[i].c1-a[i].c3) >= 0; ++i)
        {
            ans += a[i].c1;
            ++m1;
        }
        sort(a+i, a+n+1, cmp2);
        for(;i <= n && m2 < n/2 && a[i].c2-a[i].c3 >= 0; ++i)
        {
            ans += a[i].c2;
            ++m2;
        }
        sort(a+i, a+n+1, cmp3);
        for( ; i <= n && m3 < n/2; ++i)
        {
            ans += a[i].c3;
            ++m3;
        }
        sort(a+1, a+n+1, cmp1);
        for(;i <= n && m1 < n/2; ++i)
        {
            ans += a[i].c1;
            ++m1;
        }
        for(;i <= n; ++i)
        {
            ans += a[i].c2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
