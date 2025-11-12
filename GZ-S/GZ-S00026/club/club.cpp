// GZ-S00026 贵阳市观山湖区普瑞学校 何景睿
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int max_n = 1e5;


int dp[max_n];

struct Student
{
    int a1;
    int a2;
    int a3;
    int m;

    operator<(const Student& other) const
    {
        if (a1 != other.a1)
            return a1 > other.a1;
        if (a2 != other.a2)
            return a2 > other.a2;

            return a3 >= other.a3;
    }
};

Student a[max_n];

int read()
{
    int res = 0, neg = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            neg = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        res = res * 10 + (ch - '0');
        ch = getchar();
    }

    return res * neg;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t = read();

    while (t--)
    {
        int n = read();

        set<Student*> one;
        set<Student*> two;
        set<Student*> three;

        for (int i = 1; i <= n; i++)
        {
            a[i].a1 = read();
            a[i].a2 = read();
            a[i].a3 = read();
            a[i].m = max(a[i].a1, max(a[i].a2, a[i].a3));

            /*if (a[i].a1 == a[i].m)
                one.insert(&a[i]);
            else if (a[i].a2 == a[i].m)
                two.insert(&a[i]);
            else
                three.insert(&a[i]);*/
        }

        sort(a + 1, a + n + 1);


        /*for (int i = 1; i <= n; i++)
            cout << a[i].a1 << " " << a[i].a2 << " " << a[i].a3 << endl;
        cout << endl;*/

        if (a[1].a1 == 0 && a[1].a3 == 0)
        {
            int ans = 0;
            for (int i = 1; i <= n / 2; i++)
                ans += a[i].a2;
            cout << ans << endl;

            continue;
        }

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 2] + max(a[i - 1].a1 + a[i].a2, a[i - 1].a2 + a[i].a1);
        }

        cout << dp[n] << endl;
    }

    return 0;
}
