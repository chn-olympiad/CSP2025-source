#include <bits/stdc++.h>
using namespace std;

int a[205];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    int t = a[1];
    sort(a + 1, a + n * m + 1);
    reverse(a + 1, a + n * m + 1);
    for(int i = 1; i <= n * m; i++)
    {
       if(a[i] == t)
       {
           t = i;
           break;
       }
    }
    int ans1 = t % (n * 2);
    int ans2 = floor(t / (n * 2));
    if(ans1 == 0)
    {
        ans1 = n * 2;
        ans2 = ans2 - 1;
    }
    if(ans1 <= n)
    {
        cout << 2 * ans2 + 1 << " " << ans1 << endl;
        return 0;
    }
    cout << 2 * (ans2 + 1) << " " << 2 * n - ans1 + 1 << endl;

    return 0;
}
