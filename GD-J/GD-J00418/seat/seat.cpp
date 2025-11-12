#include <iostream>
#include <algorithm>

using namespace std;

int niger[114];

int n, m, fc, pos;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int r = n * m;
    for (int i = 1; i <= r; i++)
    {
        cin >> niger[i];
    }

    fc = niger[1];
    sort(niger + 1, niger + r + 1, greater<int>());

    for (int i = 1; i <= r; i++)
    {
        if (niger[i] == fc)
        {
            pos = i;
        }
    }
    // cout << pos << '\n';

    int x;
    if (pos % n == 0)
    {
        x = pos / n;
    }
    else
    {
        x = pos / n + 1;
    }

    cout << x << ' ';
    if (x % 2 == 0)
    {
        cout << n - pos % n + 1 << '\n';
    }
    else
    {
        if (pos % n == 0)
        {
            cout << n << '\n';
        }
        else
        {
            cout << pos % n << '\n';
        }
    }
    return 0;
}