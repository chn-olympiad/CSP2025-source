#include<bits/stdc++.h>
using namespace std;
int n, m, x, s[105], tot, cnt, nx, ny;
int dx[2] = {1, -1};
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in", "r", stdin);freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> x;
    s[1] = x;
    for (int i = 2; i <= n * m; i++)
    {
        cin >> s[i];
    }
    sort(s + 1, s + (n * m) + 1, cmp);
    nx = 1, ny = 1, cnt = 1;
    while (s[cnt] != x)
    {
        cnt++;
        nx += dx[tot];
        if ((nx == 1 && tot == 1) || (nx == n && tot == 0))
        {
            tot = 1 - tot;
            if (s[cnt] != x)
            {
                cnt++;
                ny++;
            }
        }
    }
    cout << ny << " " << nx << endl;
    return 0;
}
