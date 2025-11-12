#include <bits/stdc++.h>
using namespace std;
const int LEN = 1e5 + 5;
int max_ans, n, d[4][LEN], sub_A, sub_B;
void solve(int p, int ans, int num1, int num2, int num3)
{
    if (p == n + 1)
    {
        max_ans = max(max_ans, ans);
        return;
    }
    if (num1 < n/2)
        solve(p + 1, ans + d[1][p], num1 + 1, num2, num3);
    if (num2 < n / 2)
        solve(p + 1, ans + d[2][p], num1, num2 + 1, num3);
    if (num3 < n / 2)
        solve(p + 1, ans + d[3][p], num1, num2, num3 + 1);
}
void solve_subA()
{
    sort(d[1] + 1, d[1] + n + 1);
    for (int i = n; i > n / 2; i--)
        max_ans += d[1][i];
}
void solve_subB()
{
    struct kkk
    {
        int d1, d2, delta;
        bool operator<(const kkk &x) const
        {
            return delta > x.delta;
        }
    } t[LEN];
    for (int i = 1; i <= n; i++)
    {
        t[i].d1 = d[1][i];
        t[i].d2 = d[2][i];
        t[i].delta = abs(d[1][i] - d[2][i]);
    }
    sort(t + 1, t + n + 1);
    // for (int i = 1; i <= n; i++)
    //     cout << t[i].d1 << " " << t[i].d2 << " " << t[i].delta << "\n";
    int num1 = 0, num2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((t[i].d1 > t[i].d2 || num2 == n/2) && num1 < n/2)
        {
            num1++;
            max_ans += t[i].d1;
        }
        else
        {
            num2++;
            max_ans += t[i].d2;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        max_ans = 0;
        sub_A = 1;
        sub_B = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> d[1][i] >> d[2][i] >> d[3][i];
            if (d[2][i] != 0)
                sub_A = 0;
            if (d[3][i] != 0)
            {
                sub_A = 0;
                sub_B = 0;
            }
        }
        if (sub_A == 1)
            solve_subA();
        else if (sub_B == 1)
            solve_subB();
        else solve(1, 0, 0, 0, 0);
        cout << max_ans << "\n";
    }
    return 0;
}