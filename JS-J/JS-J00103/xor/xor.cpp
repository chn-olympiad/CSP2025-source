#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200010];
int oncnt = 0;
int ans = 0;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    //AB
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1) oncnt++;
        if (oncnt != 0 && oncnt % 2 == k)
        {
            ans++;
            oncnt = 0;
        }
    }
    cout << ans;
    return 0;
}
