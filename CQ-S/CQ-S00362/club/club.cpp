#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
#define int long long

int T;
int n;
int a[MAXN][5];

int ans = 0, s[5];
void DFS(int i, int total)
{
    if (i > n)
    {
        ans = max(ans, total);
        return;
    }
    for (int j = 1; j <= 3; j ++)
    {
        if (s[j] < (n >> 1))
        {
            s[j] += 1;
            DFS(i + 1, total + a[i][j]);
            s[j] -= 1;
        }
    }
}

int cnt = 0, Door;
bool ok = false;
bool Check(int i, int total, int mid)
{
    if (ok) return true;
    if (i > n)
    {
        cnt ++;
        if (total >= mid) 
        {
            ok = true;
            return true;
        }
        return false;
    }
    if (total >= mid)
    {
        ok = true;
        return true;
    }
    for (int j = 1; j <= 3; j ++)
    {
        if (s[j] < (n >> 1))
        {
            s[j] += 1;
            if (Check(i + 1, total + a[i][j], mid))
            {
                ok = true;
                return true;
            }
            s[j] -= 1;
        }
    }
    return false;
}
bool CheckFun(int mid)
{
    cnt = 0;  
    ok = false;
    s[1] = s[2] = s[3] = 0;
    bool res = Check(1, 0, mid); 
    return (res == true ? true : false);
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> T;
    while (T --)
    {
        cin >> n;
        int up = 0;
        for (int i = 1; i <= n; i ++)
        {
            int tmp = 0;
            for (int j = 1; j <= 3; j ++)
            {
                cin >> a[i][j];
                tmp = max(tmp, a[i][j]);
            }
            up += tmp;
        }

        if (n <= 16) // 暴搜
        {
            ans = 0;
            s[1] = s[2] = s[3] = 0;
            DFS(1, 0);
            cout << ans << "\n";
            continue;
        }
        bool check = true;
        for (int i = 1; i <= n; i ++)
        {
            if (a[i][1] == 0 && a[i][3] == 0 && a[i][2] != 0) continue;
            check = false;
        }
        if (check)
        {
            vector<int> b;
            for (int i = 1; i <= n; i ++)
                b.push_back(a[i][2]);
            sort(b.begin(), b.end(), greater<int>());
            int ans1 = 0;
            for (int i = 0; i < (n >> 1); i ++)
                ans1 += b[i];
            cout << ans1 << "\n";
            continue;
        }

        int l = 0, r = up;
        int res = 0;
        srand(unsigned(time(0)));
        Door = n + rand() % (n * n);
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (CheckFun(mid))
            {
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        cout << res << "\n";
    }

    return 0;
}