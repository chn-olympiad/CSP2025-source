#include <bits/stdc++.h>
using namespace std;
int dx[3] = {1, 0, -1}; //xia you shang
int dy[3] = {0, 1, 0};
int p[505];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> p[i];
    int a = p[1];
    sort(p + 1, p + 1 + n * m, greater<int>());
    int x = 1, y = 1, d = 0;
    bool f = 0;
    for (int i = 1; i <= n * m; i++)
    {
        if (p[i] == a)
        {
            cout << y << ' ' << x;
            return 0;
        }
        if (x == m)
        {
            if (y % 2)
                d = 1;
            else
                d = 2;
        }
        if (x == 1)
        {
            if (y % 2)
                d = 0;
            else
                d = 1;
        }
        x += dx[d], y += dy[d];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}