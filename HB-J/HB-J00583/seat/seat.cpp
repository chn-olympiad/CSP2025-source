#include <bits/stdc++.h>

using namespace std;

int n, m, a[105];
int R_score;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    R_score = a[1];

    sort(a + 1, a + n * m + 1, cmp);

    int L = 1, R = n * m, mid = (L + R) / 2;
    while (L < R)
    {
        if (a[mid] <= R_score)
            R = mid;
        if (a[mid] > R_score)
            L = mid + 1;

        mid = (L + R) / 2;
    }

    int c = 0, r = 1, cnt = 0;

    for (int i = 1; i <= m; i++)
    {
        c = i;
        for (int j = 1; j <= n; j++)
        {
            cnt ++;
            if (j == 1)
                ;
            else if (i % 2 == 0)
                r --;
            else if (i % 2 == 1)
                r ++;

            if (cnt == L)
            {
                cout << c << " " << r;
                return 0;
            }
        }
    }

    return 0;
}
