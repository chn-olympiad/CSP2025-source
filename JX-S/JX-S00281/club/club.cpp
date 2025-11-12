#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100001;
int t, n, ans, lmt;
int Maxn1, Maxn2, Maxn3;

struct node
{
    int x, y, z;
} a[MAXN], maxn[MAXN], tmp[MAXN];

bool cmp1(node u, node v)
{
    return u.x > v.x;
}

bool cmp2(node u, node v)
{
    return u.y > v.y;
}

bool cmp3(node u, node v)
{
    return u.z > v.z;
}

void Sorta()
{
    sort(a, a + n, cmp1);
    for (int i = 0; i < lmt; i++)
    {
        ans += a[i].x;
        a[i].y = -1;
        a[i].z = -1;
    }
}

void Sortb()
{
    sort(a, a + n, cmp2);
    for (int i = 0; i < lmt; i++)
    {
        ans += a[i].y;
        a[i].x = -1;
        a[i].z = -1;
    }
}

void Sortc()
{
    sort(a, a + n, cmp3);
    for (int i = 0; i < lmt; i++)
    {
        ans += a[i].z;
        a[i].x = -1;
        a[i].y = -1;
    }
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int sumy = 0, sumz = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].x >> a[i].y >> a[i].z;
            sumy += a[i].y;
            sumz = a[i].z;
            tmp[i].x = a[i].x;
            tmp[i].y = a[i].y;
            tmp[i].z = a[i].z;
        }
        if (sumy == 0 && sumz == 0)
        {
            Sorta();
            cout << ans << '\n';
            ans = 0;
        }
        else
        {
            lmt = n / 2;
            for (int i = 0; i < lmt; i++)
            {
                int maxn1 = 0, maxn2 = 0, maxn3 = 0;
                for (int j = 0; j < n; j++)
                {
                    maxn1 = max(tmp[j].x, maxn1);
                    tmp[j].x = -1;
                    maxn2 = max(tmp[j].y, maxn2);
                    tmp[j].y = -1;
                    maxn3 = max(tmp[j].z, maxn3);
                    tmp[j].z = -1;
                }
                maxn[i].x = maxn1;
                maxn[i].y = maxn2;
                maxn[i].z = maxn3;
            }
            Maxn1 = 0, Maxn2 = 0, Maxn3 = 0;
            for (int i = 0; i < lmt; i++)
            {
                Maxn1 += maxn[i].x;
                Maxn2 += maxn[i].y;
                Maxn3 += maxn[i].z;
            }
            if (Maxn1 > Maxn2)
            {
                if (Maxn2 > Maxn3)
                {
                    Sorta();
                    Sortb();
                    Sortc();
                }
                else
                {
                    if (Maxn3 > Maxn1)
                    {
                        Sortc();
                        Sorta();
                        Sortb();
                    }
                    else
                    {
                        Sorta();
                        Sortc();
                        Sortb();
                    }
                }
            }
            else
            {
                if (Maxn3 > Maxn2)
                {
                    Sortc();
                    Sortb();
                    Sorta();
                }
                else
                {
                    if (Maxn1 > Maxn3)
                    {
                        Sortb();
                        Sorta();
                        Sortc();
                    }
                    else
                    {   
                        Sortb();
                        Sortc();
                        Sorta();
                    }
                }
            }
            cout << ans << '\n';
            ans = 0;
        }
    }
    return 0;
}