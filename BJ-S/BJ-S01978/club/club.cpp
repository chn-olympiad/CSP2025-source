#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct node
{
    int b, c, d;
}a[N];
int t, n;
bool cmp1(node x, node y)
{
    return x.b > y.b;
}
bool cmp2(node x, node y)
{
    return abs(x.b - x.c) > abs(y.b - y.c);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while (t--)
    {
        int cnt1 = 0, cnt2 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].b >> a[i].c >> a[i].d;
            if (a[i].c == 0 && a[i].d == 0)
                cnt1++;
            if (a[i].d == 0)
                cnt2++;
        }
        if (n == 2)
            cout << max( max( max(a[1].b + a[2].c, a[1].b + a[2].d), a[1].c + a[2].b), max( max(a[1].c + a[2].d, a[1].d + a[2].b), a[1].d + a[2].c) ) << endl;
        else if (cnt1 == n)
        {
            sort(a+1, a+1+n, cmp1);
            int ans1 = 0;
            for (int i = 1; i <= n / 2; i++)
                ans1 += a[i].b;
            cout << ans1 << endl;
        }
        else if (cnt2 == n)
        {
            sort(a+1, a+1+n, cmp2);
            int ans2 = 0, n1 = 0, n2 = 0;
            for (int i = 1; i <= n; i++)
            {
                if (a[i].b > a[i].c)
                {
                    if (n1 == n / 2)
                    {
                        n2++;
                        ans2 += a[i].c;
                    }
                    else
                    {
                        n1++;
                        ans2 += a[i].b;
                    }
                }
                else if (a[i].b <= a[i].c)
                {
                    if (n2 == n / 2)
                    {
                        n1++;
                        ans2 += a[i].b;
                    }
                    else
                    {
                        n2++;
                        ans2 += a[i].c;
                    }
                }
            }
            cout << ans2 << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
