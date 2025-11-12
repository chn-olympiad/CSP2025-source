#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long x, y, z, c, cc, maxn, minn, mg;
}a[100005];
int cn[5];
bool cmp(node x, node y)
{
    if (x.c != y.c) return x.c > y.c;
    if (x.cc != y.cc) return x.cc > y.cc;
    if (x.maxn != y.maxn) return x.maxn > y.maxn;
    if (x.mg != y.mg) return x.mg > y.mg;
    return x.minn > y.minn;
}
int check(int x, long long k)
{
    if (a[x].x == k) return 1;
    if (a[x].y == k) return 2;
    return 3;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].x >> a[i].y >> a[i].z;
            a[i].maxn = max({a[i].x, a[i].y, a[i].z});
            a[i].minn = min({a[i].x, a[i].y, a[i].z});
            if (a[i].x != a[i].maxn && a[i].x != a[i].minn) a[i].mg = a[i].x;
            else if (a[i].y != a[i].maxn && a[i].y != a[i].minn) a[i].mg = a[i].y;
            else if (a[i].z != a[i].maxn && a[i].z != a[i].minn) a[i].mg = a[i].z;
            a[i].c = a[i].maxn - a[i].mg;
            a[i].cc = a[i].mg - a[i].minn;
        }
        sort(a + 1, a + n + 1, cmp);
        long long sum = 0;
        cn[1] = cn[2] = cn[3] = 0;
        for (int i = 1; i <= n; i++)
        {
            //cout << a[i].maxn << " " << a[i].mg << " " << a[i].minn << " ";
            if (cn[check(i, a[i].maxn)] < n / 2)
            {
                //cout << check(i, a[i].maxn) << " " << cn[check(i, a[i].maxn)];
                sum += a[i].maxn;
                cn[check(i, a[i].maxn)]++;
            }
            else if (cn[check(i, a[i].mg)] < n / 2)
            {
                //cout << check(i, a[i].mg) << " ";
                sum += a[i].mg;
                cn[check(i, a[i].mg)]++;
            }
            else
            {
                //cout << check(i, a[i].minn) << " ";
                sum += a[i].minn;
                cn[check(i, a[i].minn)]++;
            }
            //cout << endl;
        }
        cout << sum << endl;
    }
    return 0;
}
