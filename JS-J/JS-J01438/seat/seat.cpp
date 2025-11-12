#include <bits/stdc++.h>
using namespace std;
int seat[105];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int s = n * m;
    for(int i = 1; i <= s; i++)
    {
        cin >> seat[i];
    }
    int x = seat[1];
    sort(seat + 1, seat + s + 1, cmp);
    int pos;
    for(int i = 1; i <= s; i++)
    {
        if(seat[i] == x)
        {
            pos = i;
            break;
        }
    }
    int r, c, y = pos % n;
    if(y == 0)
    {
        y = n;
        c = pos / n;
    }
    else
    {
        c = pos / n + 1;
    }
    if(c % 2)
    {
        r = y;
    }
    else
    {
        r = n - y + 1;
    }
    cout << c << ' ' << r << '\n';
    return 0;
}
//expected 100pts