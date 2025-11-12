#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int a[105], s[15][15];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    r = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1; i <= n * m; i++)
    {
        if(a[i] == r)
        {
            int l = (i - 1) / n + 1;
            if(l % 2 == 1)
            {
                int h;
                if(i % n == 0)
                    h = n;
                else
                    h = i % n;
                cout << l << " " << h << '\n';
                return 0;
            }
            if(l % 2 == 0)
            {
                int h;
                if(i % n == 0)
                    h = 1;
                else
                    h = n - i % n + 1;
                cout << l << " " << h << '\n';
                return 0;
            }
        }
    }
    return 0;
}
