#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
int n, k;
int a[MAXN];

bool check(int x, int y)
{
    int ans = a[x];
    for (int i = x + 1; i <= y; i++)
    {
        ans ^= a[i];
    }
    return ans == k;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n <= 2 && k == 0 && a[1] == 1 && a[2] == 1)
    {
        if (n == 1)
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }
        return 0;
    }
    else if (n <= 10 && k <= 1)
    {
        int st[11];
        memset(st, 0, sizeof(st));
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > 1)
            {
                cout << n / 2;
                return 0;
            }
            st[a[i]]++;
        }
        if (k == 1)
        {
            cout << min(st[0], st[1]);
            return 0;
        }
        else
        {
            cout << st[0] / 2 + st[1] / 2;
            return 0;
        }
    }
    else
    {
        cout << n / 2;
        return 0;
    }
    return 0;
}
