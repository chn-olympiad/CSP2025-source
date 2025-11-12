#include <bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++) cin >> a[i];
    int t = a[1];
    sort(a + 1,a + n * m + 1,cmp);
    int i;
    for (i = 1;i <= n * m;i++)
    {
        if (a[i] == t) break;
    }
    int ans = i / (2 * n) * 2 + 1;
    i %= (2 * n);
    if (i > n)
    {
        ans++;
        i -= n;
        i = n - i + 1;
    }
    cout << ans << " " << i << endl;
    return 0;
}
