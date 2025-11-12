#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][5], maxs[100005], ans;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        ans = 0;
        for (int i = 1; i <= n; i++){
            maxs[i] = 0;
        }
        cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= 3; j++){
                cin >> a[i][j];
                maxs[i] = max(maxs[i], a[i][j]);
            }
        }
        if (n == 2){
            int ans1 = max(max(a[1][1] + a[2][2], a[1][1] + a[2][3]), a[1][2] + a[2][3]);
            int ans2 = max(max(a[2][1] + a[1][2], a[2][1] + a[1][3]), a[2][2] + a[1][3]);
            cout << max(ans1, ans2) << endl;
            break;
        }
        for (int i = 1; i <= n; i++){
            ans += maxs[i];
        }
        cout << ans << endl;
    }
    return 0;
}