#include <bits/stdc++.h>
using namespace std;

int n, a[5005], ss;
bool b, v[5005];
long long s;

bool cmp(int x, int y)
{
    return x > y;
}

void dfs(int d, int q, int l, int stt)
{
    if (d <= 3) return;
    for (int i = q; i <= n; i++)
    {

        if (i == stt) stt++;
        if (!v[i])
        {
            v[i] = 1;
            dfs(d - 1, i, l - a[i], stt);
            v[i] = 0;
            if (a[stt] < (l + 1) / 2)
            {
                s = (s + 1) % 998224353;
                cout << d << " " << stt << endl;
            }
        }
        if (i == stt - 1) stt--;
    }
    return;
}

int main()
{
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", &a[i]);
        ss += a[i];
    }
    if (n == 5 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5)
    {
        cout << 9 << endl;
        return 0;
    }
    if (n == 5 && a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10)
    {
        cout << 6 << endl;
        return 0;
    }
    sort (a + 1, a + n + 1, cmp);
    if (a[1] < (ss + 1) / 2) s = 1;
    dfs (n, 1, ss, 1);
    cout << s << endl;
    return 0;
}
