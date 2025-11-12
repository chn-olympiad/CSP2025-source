#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int read()
{
    int x = 0, k = 1;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') k = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * k;
}
struct node
{
    int d1, d2, d3;
    int df, df1, df2;
    bool f;
}a[100005];
bool cmp(node x, node y)
{
    return x.d1 > y.d1;
}
bool cmp2(node x, node y)
{
    return x.d2 > y.d2;
}
bool cmp3(node x, node y)
{
    return x.df < y.df;
}
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t = read();
    while(t--)
    {
        int n = read(), op = 1, cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            a[i].d1 = read(), a[i].d2 = read(), a[i].d3 = read();
            a[i].df = abs(a[i].d1 - a[i].d2);
            a[i].df1 = abs(a[i].d1 - a[i].d3);
            a[i].df2 = abs(a[i].d2 - a[i].d3);
            if(a[i].d2 != 0 || a[i].d3 != 0) op = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            if(a[i].d3 != 0) op = -1;
        }
        if(op == 0) op = 2;
        if(op == 1)
        {
            sort(a + 1, a + n + 1, cmp);
            for(int i = 1; i <= n / 2; i++) cnt += a[i].d1;
            cout << cnt << endl;
            cnt = 0;
            continue;
        }
        else if(op == 2)
        {
            int t1 = 0, t2 = 0;
            for(int i = 1; i <= n; i++)
            {
                if(a[i].d1 >= a[i].d2)
                {
                    t1++;
                    cnt += a[i].d1;
                }
                if(a[i].d2 > a[i].d1)
                {
                    t2++;
                    cnt += a[i].d2;
                }
            }
            if(t1 > t2)
            {
                for(int i = 1; i <= n; i++)
                {
                    if(max(a[i].d1, a[i].d2) == a[i].d1)
                    {
                        continue;
                    }
                    a[i].df = 1e9;
                }
                sort(a + 1, a + n + 1, cmp3);
                for(int i = 1; t1 - i >= n / 2; i++)
                {
                    cnt -= a[i].df;
                }
            }
            else
            {
                for(int i = 1; i <= n; i++)
                {
                    if(max(a[i].d1, a[i].d2) == a[i].d2)
                    {
                        continue;
                    }
                    a[i].df = 1e9;
                }
                sort(a + 1, a + n + 1, cmp3);
                for(int i = 1; t2 - i >= n / 2; i++)
                {
                    cnt -= a[i].df;
                }
            }
            cout << cnt << endl;
        }
        else
        {
            int t1 = 0, t2 = 0, t3 = 0;
            for(int i = 1; i <= n; i++)
            {
                if(max(a[i].d1, max(a[i].d2, a[i].d3)) == a[i].d1)
                {
                    t1++;
                    cnt += a[i].d1;
                }
                if(max(a[i].d1, max(a[i].d2, a[i].d3)) == a[i].d2)
                {
                    t2++;
                    cnt += a[i].d2;
                }
                if(max(a[i].d1, max(a[i].d2, a[i].d3)) == a[i].d3)
                {
                    t3++;
                    cnt += a[i].d3;
                }
            }
            if(t1 > n / 2)
            {
                for(int i = 1; i <= n; i++)
                {
                    if(max(a[i].d1, max(a[i].d2, a[i].d3)) == a[i].d1)
                    {
                        a[i].df = min(a[i].df, a[i].df1);
                    }
                    else a[i].df = 1e9;
                }
                sort(a + 1, a + n + 1, cmp3);
                for(int i = 1; t1 - i >= n / 2; i++)
                {
                    cnt -= a[i].df;
                }
            }
            if(t3 > n / 2)
            {
                for(int i = 1; i <= n; i++)
                {
                    if(max(a[i].d1, max(a[i].d2, a[i].d3)) == a[i].d3)
                    {
                        a[i].df = min(a[i].df1, a[i].df2);
                    }
                    else a[i].df = 1e9;
                }
                sort(a + 1, a + n + 1, cmp3);
                for(int i = 1; t3 - i >= n / 2; i++)
                {
                    cnt -= a[i].df;
                }
            }
            if(t2 > n / 2)
            {
                for(int i = 1; i <= n; i++)
                {
                    if(max(a[i].d1, max(a[i].d2, a[i].d3)) == a[i].d2)
                    {
                        a[i].df = min(a[i].df, a[i].df2);
                    }
                    else a[i].df = 1e9;
                }
                sort(a + 1, a + n + 1, cmp3);
                for(int i = 1; t2 - i >= n / 2; i++)
                {
                    cnt -= a[i].df;
                }
            }
            cout << cnt << endl;
            continue;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
