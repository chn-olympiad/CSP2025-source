#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int N = 15;
const int inf = 0x3f3f3f3f;
int a[N * N], n, m;
void work()
{
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin >> a[(i - 1) * m + j];
    int R = a[1];
    sort(a + 1, a + n * m + 1);
    reverse(a + 1, a + n * m + 1);
    int x = 1, y = 1, op = 1;
    for (int i=1;i<=n*m;i++)
    {
        if (a[i] == R)
        {
            cout << y << ' ' << x;
            return;
        }
        if (op)
        {
            if (x == n)
                y ++, op = 0;
            else
                x ++;
        }
        else
        {
            if (x == 1)
                y ++, op = 1;
            else
                x --;
        }
    }
}
int main()
{
    freopen("seat.in", "r", stdin);freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _T = 1;
    //cin >> _T;
    while (_T --)
        work();
    return 0;
}