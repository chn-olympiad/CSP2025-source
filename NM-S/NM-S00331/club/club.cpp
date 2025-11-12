#include <bits/stdc++.h>
using namespace std;
int t, n;
int stfa, stfb, stfc;
struct student
{
    int a, b, c;
    bool used = 0;
}stf[100005];
bool cmp1(student x, student y)
{
    return x.a > y.a;
}
bool cmp2(student x, student y)
{
    return x.b > y.b;
}
bool cmp3(student x, student y)
{
    return x.c > y.c;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> stf[i].a >> stf[i].b >> stf[i].c;
        }
        int ct = 0;
        for (int i = 1; i <= n; i++)
        {
            if (stf[i].a > stf[i].b && stf[i].a > stf[i].c)
            {
                ct = 0;
                sort(stf + 1, stf + n + 1, cmp1);
                for (int i = 1; i <= n; i++)
                {
                    if (stf[i].used == 0 && ct + 1 <= n / 2)
                    {
                        ct++;
                        stfa += stf[i].a;
                        stf[i].used = 1;
                    }
                }
            }
            if (stf[i].b > stf[i].a && stf[i].b > stf[i].c)
            {
                ct = 0;
                sort(stf + 1, stf + n + 1, cmp2);
                for (int i = 1; i <= n; i++)
                {
                    if (stf[i].used == 0 && ct + 1 <= n / 2)
                    {
                        ct++;
                        stfb += stf[i].b;
                        stf[i].used = 1;
                    }
                }
            }
            if (stf[i].c > stf[i].a && stf[i].c > stf[i].b)
            {
                ct = 0;
                sort(stf + 1, stf + n + 1, cmp2);
                for (int i = 1; i <= n; i++)
                {
                    if (stf[i].used == 0 && ct + 1 <= n / 2)
                    {
                        ct++;
                        stfc += stf[i].c;
                        stf[i].used = 1;
                    }
                }
            }
        }
    }
    cout << stfa + stfb + stfc << endl;
    return 0;
}
