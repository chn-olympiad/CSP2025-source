#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a, r = 1;
    cin >> a;
    for (int i = 2; i <= n * m; i++)
    {
        int sc;
        cin >> sc;
        if (sc > a) r++;
    }
    int t = (r - 1) / n + 1, tt = r % n;
    if (t %  2== 0)
    {
        if (tt == 0) cout << t <<  ' ' << 1;
        else cout << t << ' ' << n + 1 - tt;
    }
    else
    {
        if (tt == 0) cout << t << ' ' << n;
        else cout << t << ' ' << tt;
    }
    return 0;
}
