#include <bits/stdc++.h>
using namespace std;
struct node
{
    int v1, v2, v3;
};
bool cmp1(node X, node Y)
{
    if (X.v1 - max(X.v2, X.v3) == Y.v1 - max(Y.v2, Y.v3)) return X.v1 < Y.v1;
    return X.v1 - max(X.v2, X.v3) > Y.v1 - max(Y.v2, Y.v3);
}
bool cmp2(node X, node Y)
{
    if (X.v2 - max(X.v1, X.v3) == Y.v2 - max(Y.v1, Y.v3)) return X.v2 < Y.v2;
    return X.v2 - max(X.v1, X.v3) > Y.v2 - max(Y.v1, Y.v3);
}
bool cmp3(node X, node Y)
{
    if (X.v3 - max(X.v1, X.v2) == Y.v3 - max(Y.v1, Y.v2)) return X.v3 < Y.v3;
    return X.v3 - max(X.v1, X.v2) > Y.v3 - max(Y.v1, Y.v2);
}
int T, n;
node a[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        int ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i].v1 >> a[i].v2 >> a[i].v3;
        for (int i = 1; i <= n; i++)
        {
            if (a[i].v1 >= a[i].v2 && a[i].v1 >= a[i].v3) cnt1++;
            else if (a[i].v2 >= a[i].v3) cnt2++;
            else cnt3++;
        }
        if (cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2)
        {
            for (int i = 1; i <= n; i++) ans += max(max(a[i].v1, a[i].v2), a[i].v3);
        }
        else if (cnt1 > n / 2)
        {
            sort(a + 1, a + n + 1, cmp1);
            for (int i = 1; i <= n / 2; i++) ans += a[i].v1;
            for (int i = n / 2 + 1; i <= n; i++) ans += max(a[i].v2, a[i].v3);
        }
        else if (cnt2 > n / 2)
        {
            sort(a + 1, a + n + 1, cmp2);
            for (int i = 1; i <= n / 2; i++) ans += a[i].v2;
            for (int i = n / 2 + 1; i <= n; i++) ans += max(a[i].v1, a[i].v3);
        }
        else
        {
            sort(a + 1, a + n + 1, cmp3);
            for (int i = 1; i <= n / 2; i++) ans += a[i].v3;
            for (int i = n / 2 + 1; i <= n; i++) ans += max(a[i].v2, a[i].v1);
        }
        cout << ans << '\n';
    }
    return 0;
}
// 密码的一个条件给我条了30分钟
// 西西佛神机保佑我100pts!!!