#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int ll
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e5 + 5;
bool __st__;
int n;
int a[N][3];
int fav[N][3];
priority_queue<pii, vector<pii>, greater<pii>> q[3];
int pto;
int In(int i, int p, int org) // return -1 if suc and x if x pop;
{
    if ((int)q[p].size() * 2 < n)
    {
        pto += a[i][p];
        q[p].push({a[i][p] - a[i][fav[i][org - 1]], i});
        return -1;
    }
    else
    {
        pii tp = q[p].top();
        int tpid = tp.second, tpval = tp.first;
        q[p].pop();
        if (tpval < a[i][p] - a[i][fav[i][org - 1]])
        {
            pto += a[i][p] - a[tpid][p];
            q[p].push({a[i][p] - a[i][fav[i][org - 1]], i});
            return tpid;
        }
        else
        {
            q[p].push(tp);
            return i;
        }
    }
}
int curr;
bool cmp(int x, int y)
{
    return a[curr][x] < a[curr][y];
}
void solve()
{
    cin >> n;
    pto = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        curr = i;
        sort(fav[i], fav[i] + 3, cmp);
        int fst = In(i, fav[i][2], 2);
        if (fst == -1)
            continue;
        int nxt = In(fst, fav[fst][1], 1);
        // if (nxt != -1)
        //     cerr << "?" << nxt << '\n';
    }
    for (int i = 0; i < 3; i++)
        while (q[i].size())
            q[i].pop();
    cout << pto << '\n';
}
bool __ed__;
void PrintMemUse() { cerr << (&__st__ - &__ed__) / 1048576.0 << '\n'; }
signed main()
{
    FASTIO;
    // PrintMemUse(); // 2.8906
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    for (int i = 1; i <= 1e5; i++)
        for (int j = 0; j < 3; j++)
            fav[i][j] = j;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
/*
g++ club.cpp -o club.exe -std=c++14 -O2 '-Wl,--stack=536870912' -Wall
./club.exe



1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/