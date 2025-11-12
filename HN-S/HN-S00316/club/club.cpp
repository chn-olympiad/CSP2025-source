// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// const int N = 1e5 + 5;
// int n, m = 3;
// ll sum;

// struct Node
// {
//     int v, id;
// } a[N][4];

// int cnt[4];

// bool cmp(Node a, Node b)
// {
//     return a.v > b.v;
// }

// void solve()
// {
//     cnt[1] = cnt[2] = cnt[3] = sum = 0;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             cin >> a[i][j].v;
//             a[i][j].id = j;
//         }
//         sort(a[i] + 1, a[i] + m + 1, cmp);
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         int id1 = a[i][1].id, id2 = a[i][2].id, id3 = a[i][3].id;
//         int v1 = a[i][1].v, v2 = a[i][2].v, v3 = a[i][3].v;
//         if (cnt[id1] < n / 2)
//         {
//             sum += v1
//             cnt[id1]++;
//         }
//         else
//         {
//             if (cnt[id2] < n / 2)
//             {
//                 sum += v2;
//                 cnt[id2]++;
//             }
//             else
//             {
//                 sum += v3;
//                 cnt[id3]++;
//             }
//         }
//     }
//     cout << sum << '\n';
// }

// /*
// 4
// 0 1 0
// 0 1 0
// 0 2 0
// 0 2 0
// */


// signed main()
// {
//     freopen("club1.in", "r", stdin);
//     // freopen("club1.out", "w", stdout);
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int T;
//     cin >> T;
//     while (T--) solve();
//     return 0;
// }



#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, m = 3;
ll sum;

struct Node
{
    int v, id;
    // bool operator < (const Node &it) const
    // {
    //     return v < id.v;
    // }
} a[N][4];

int cnt[4];

bool cmp(Node a, Node b)
{
    return a.v > b.v;
}

priority_queue<int, vector<int>, greater<int>> q[4][4];

void solve()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            while (!q[i][j].empty()) q[i][j].pop();
        }
    }
    cnt[1] = cnt[2] = cnt[3] = sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j].v;
            a[i][j].id = j;
        }
        sort(a[i] + 1, a[i] + m + 1, cmp);
    }
    for (int i = 1; i <= n; i++)
    {
        int id1 = a[i][1].id, id2 = a[i][2].id, id3 = a[i][3].id;
        // cout << id1 << ' ' << id2 << ' ' << id3 << '\n';
        int v1 = a[i][1].v, v2 = a[i][2].v, v3 = a[i][3].v;
        // cout << v1 << ' ' << v2 << ' ' << v3 << '\n';
        if (cnt[id1] < n / 2)
        {
            // cout << "cnt[id1] < n / 2" << '\n';
            cnt[id1]++;
            // cout << "cnt = " << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << '\n';
            sum += v1;
            // cout << "sum = " << sum << '\n';
            q[id1][id2].push(v1 - v2);
            q[id1][id3].push(v1 - v3);
        }
        else
        {
            // cout << "not cnt[id1] < n / 2" << '\n';
            if (cnt[id2] < n / 2)
            {
                // cout << "cnt[id2] < n / 2" << '\n';
                int tmp1 = q[id1][id2].top(), tmp2 = q[id1][id3].top();
                // cout << "tmp = " << tmp1 << ' ' << tmp2 << '\n';
                // cout << "v1 - v2 = " << v1 - v2 << '\n';
                if (tmp1 > v1 - v2 && tmp2 > v1 - v2)
                {
                    cnt[id2]++;
                    sum += v2;
                    q[id2][id1].push(v2 - v1);
                    q[id2][id3].push(v2 - v3);
                }
                else
                {
                    if (cnt[id3] < n / 2 && tmp2 < tmp1)
                    {
                        cnt[id3]++;
                        sum -= tmp2;
                        q[id1][id3].pop();
                        sum += v1;
                        q[id1][id2].push(v1 - v2);
                        q[id1][id3].push(v1 - v3);
                    }
                    else
                    {
                        cnt[id2]++;
                        sum -= q[id1][id2].top();
                        q[id1][id2].pop();
                        sum += v1;
                        q[id1][id2].push(v1 - v2);
                        q[id1][id3].push(v1 - v3);
                    }
                }
                // cout << "cnt = " << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << '\n';
                // cout << "sum = " << sum << '\n';
            }
            else
            {
                if (cnt[id3] < n / 2)
                {
                    if (q[id1][id3].top() < v1 - v3)
                    {
                        cnt[id3]++;
                        sum -= q[id1][id3].top();
                        sum += v1;
                        q[id1][id2].push(v1 - v2);
                        q[id1][id3].push(v1 - v3);
                    }
                    else
                    {
                        if (q[id2][id3].top() < v2 - v3)
                        {
                            cnt[id3]++;
                            sum -= q[id2][id3].top();
                            sum += v2;
                            q[id2][id1].push(v2 - v1);
                            q[id2][id3].push(v2 - v3);
                        }
                        else
                        {
                            cnt[id3]++;
                            sum += v3;
                            q[id3][id1].push(v3 - v1);
                            q[id3][id2].push(v3 - v2);
                        }
                    }
                }
            }
        }
    }
    cout << sum << '\n';
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}