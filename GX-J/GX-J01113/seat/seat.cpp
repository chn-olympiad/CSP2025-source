#include<iostream>
#include<algorithm>
using namespace std;

freopen("seat.in", 'r', stdin);
freopen("seat.out", 'w', stdout);

struct p
{
    int s;
    bool r = 0;
};

int cmp(p a, p b)
{
    return a.s > b.s;
}

int main()
{
    int n, m, rn, rm, r;
    p a[100];
    cin >> n >> m;
    for (int i = 0; i < n * m; i++)
    {
        cin >> a[i].s;
    }
    a[0].r = 1;
    sort(a, a + n * m, cmp);
    for (int i = 0; i < n * m; i++)
    {
        if (a[i].r)
        {
            r = i;
        }
    }
    rm = r / m + 1;
    rn = r % m + 1;
    if (rm % 2 == 0)
    {
        rn = m - rn + 1;
    }
    cout << rm << ' ' << rn;
    return 0;
}