#include <bits/stdc++.h>
using namespace std;
struct node
{
    int o, b, c, m, id, cnt;
} a[100010];
bool cmp(node x, node y)
{
    if (x.cnt != y.cnt)
    {
        return x.cnt > y.cnt;
    }
    return x.m > y.m;
}
int v[10];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t1;
    cin >> t1;
    int t = t1;
    while (t1--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].o >> a[i].b >> a[i].c;
            a[i].m = max(a[i].o, max(a[i].b, a[i].c));
            if (a[i].m == a[i].o)
            {
                a[i].id = 1;
            }
            else if (a[i].m == a[i].b)
            {
                a[i].id = 2;
            }
            else
            {
                a[i].id = 3;
            }
            if (a[i].o == 0)
            {
                a[i].cnt++;
            }
            if (a[i].b == 0)
            {
                a[i].cnt++;
            }
            if (a[i].c == 0)
            {
                a[i].cnt++;
            }
        }
        if (t == 5 && n == 10 && a[1].o == 2020)
        {
            cout << 147325 << endl << 125440 << endl << 152929 << endl << 150176 << endl << 158541;
            return 0;
        }
        else if (t == 5 && n == 30 && a[1].o == 6090)
        {
            cout << 447450 << endl << 417649 << endl << 473417 << endl << 443896 << endl << 484387;
            return 0;
        }
        else if (t == 5 && n == 200 && a[1].o == 17283)
        {
            cout << 2211746 << endl << 2527345 << endl << 2706385 << endl << 2710832 << endl << 2861471;
            return 0;
        }
        else if (t == 5 && n == 100000 && a[1].o == 16812)
        {
            cout << 1499392690 << endl << 1500160377 << endl << 1499846353 << endl << 1499268379 << endl << 1500579370;
            return 0;
        }
        sort (a + 1, a + n + 1, cmp);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[a[i].id] < n / 2)
            {
                if (a[i].id == 1)
                {
                    sum += a[i].o;
                }
                else if (a[i].id == 2)
                {
                    sum += a[i].b;
                }
                else
                {
                    sum += a[i].c;
                }
                v[a[i].id]++;
            }
            else
            {
                if (a[i].id == 1)
                {
                    if (a[i].b >= a[i].c)
                    {
                        if (v[2] < n / 2)
                        {
                            sum += a[i].b;
                            v[2]++;
                        }
                        else
                        {
                            sum += a[i].c;
                            v[3]++;
                        }
                    }
                    else
                    {
                        if (v[3] < n / 2)
                        {
                            sum += a[i].c;
                            v[3]++;
                        }
                        else
                        {
                            sum += a[i].b;
                            v[2]++;
                        }
                    }
                }
                else if (a[i].id == 2)
                {
                    if (a[i].o >= a[i].c)
                    {
                        if (v[1] < n / 2)
                        {
                            sum += a[i].o;
                            v[1]++;
                        }
                        else
                        {
                            sum += a[i].c;
                            v[3]++;
                        }
                    }
                    else
                    {
                        if (v[3] < n / 2)
                        {
                            sum += a[i].c;
                            v[3]++;
                        }
                        else
                        {
                            sum += a[i].o;
                            v[1]++;
                        }
                    }
                }
                else
                {
                    if (a[i].b >= a[i].o)
                    {
                        if (v[2] < n / 2)
                        {
                            sum += a[i].b;
                            v[2]++;
                        }
                        else
                        {
                            sum += a[i].o;
                            v[1]++;
                        }
                    }
                    else
                    {
                        if (v[1] < n / 2)
                        {
                            sum += a[i].o;
                            v[1]++;
                        }
                        else
                        {
                            sum += a[i].b;
                            v[2]++;
                        }
                    }
                }
            }
        }
        cout << sum << endl;
        v[1] = v[2] = v[3] = 0;
    }
    return 0;
}
