#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
    return x < y;
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, a[10005], cnt = 0;
    cin >> n;
    for (int i = 1;i <= 3;i++)
        cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    if (a[1] + a[2] > a[3])
        cnt++;
    cout << cnt;
    return 0;
}
