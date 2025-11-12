#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[100005][3];
//n <= 200 (baoli)
    long long dp[205][205][205];
void sub1()
{
    memset(dp, -0x3f, sizeof(dp));
    dp[1][0][0] = a[1][0];
    dp[0][1][0] = a[1][1];
    dp[0][0][1] = a[1][2];
    for (long long i = 2; i <= n; i ++)
    {
        for (long long j = n; j >= 0; j --)
        {
            for (long long k = i - j; k >= 0; k --)
            {
                long long l = i - j - k;
                if (j != 0 && j <= n / 2)
                {
                    dp[j][k][l] = max(dp[j][k][l],  dp[j - 1][k][l] + a[i][0]);
                }
                if (k != 0 && k <= n / 2)
                {
                    dp[j][k][l] = max(dp[j][k][l],  dp[j][k - 1][l] + a[i][1]);
                }
                if (l != 0 && l <= n / 2)
                {
                    dp[j][k][l] = max(dp[j][k][l],  dp[j][k][l - 1] + a[i][2]);
                }
            }
        }
    }
    long long ans = 0;
    for (long long i = 0; i <= n; i ++)
    {
        for (long long j = 0; j <= n; j ++)
        {
            for (long long k = 0; k <= n; k ++)
            { 
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans;
    return;
}
// A
    struct STRU
    {
        long long a, b, c;
    }A[100005];
    bool cmp(STRU x, STRU y){return x.a > y.a;};
void sub2()
{
    memset(A, 0, sizeof(A));
    for (int i = 1; i <= n; i ++)
    {
        A[i] = {a[i][0], a[i][1], a[i][2]};
    }
    sort(A + 1, A + n + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= n / 2; i ++)
    {
        ans += A[i].a;
    }
    cout << ans;
    return;
}
// B
    // struct node
    // {
    //     long long id, x;
    // };
    // priority_queue <node, vector <node>, greater <node>> q0, q1;
    // long long  cnt[3];
// void sub3()
// {
//     memset(A, 0, sizeof(A));
//     for (int i = 1; i <= n; i ++)
//     {
//         A[i] = {a[i][0], a[i][1], a[i][2]};
//     }
//     long long ans = 0;
//     for (int i = 1; i <= n; i ++)
//     {
//         if (A[i].a > A[i].b)
//         {
//             if (cnt[0] < n / 2)
//             {
//                 q0.push({i, A[i].a - A[i].b});
//                 cnt[0] ++;
//                 ans += A[i].a;
//             }
//             else
//             {
//                 if (q0.top())
//             }
//         }
//         else
//         {
//             if (cnt[0] < n / 2)
//             {
//                 q1.push({i, A[i].a - A[i].b});
//                 cnt[1] ++;
//                 ans += A[i].b;
//             }
//         }
//     }
// }
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    long long t; cin >> t;
    while (t --)
    {
        bool is_A = 1, is_B = 1;
        cin >> n;
        memset(a, 0, sizeof(a));
        for (long long i = 1; i <= n; i ++)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if (a[i][1] != 0)
            {
                is_A = 0;
                is_B = 0;
            }
            if (a[i][2] == 0)
            {
                is_A = 0;
            }
        }
        if (n <= 200)
        {
            sub1();
        }
        else if (is_A)
        {
            sub2();
        }
        // else if (is_B)
        // {
        //     sub3();
        // }
        cout << "\n";
    }
    return 0;
}