#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int a[5005];
int jie(int c)
{
    long long ans = 1;
    for(int i = 1; i <= c; i++)
        ans *= i;
    return ans;
}
int sum(int x, int y)
{
    return jie(y) / jie(x) / jie(y - x);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(n == 3)
    {
        int maxnn = max(max(a[1], a[2]), a[3]);
        int anss = a[1] + a[2] + a[3];
        if(anss > 2 * maxnn) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    if(a[n] == 1)
    {
        unsigned long long ans = 0;
        for(int i = n; i >= 3; i--)
            ans += sum(i, n), ans %= N;
        cout << ans << endl;
        return 0;
    }

    return 0;
}
