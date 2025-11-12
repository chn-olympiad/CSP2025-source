#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int a[100100];
        cin >> n;
        for (int i = 1; i <= n; i ++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            a[i] = x;
        }
        sort(a+1, a+n+1, cmp);
        long long ans = 0;
        for (int i = 1; i <= n/2; i ++) ans += a[i];
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
