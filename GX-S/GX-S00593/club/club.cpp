#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out" ,"w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int m, ans = 0;
        cin >> m;
        int A = 0, B = 0, C = 0;
        int a[m + 1], b[m + 1], c[m + 1];
        for(int k = 0; k < m; k++)
        {
            cin >> a[k] >> b[k] >> c[k];
        }
        for(int x = 0; x < m - 1; x++)
        {
            for(int y = x + 1; y < m; y++)
            {
                if(a[x] == a[y] && c[x] == c[y])
                {
                    if(b[x] < b[y])
                        swap(b[x], b[y]);
                }
                else if(a[x] == a[y] && b[x] == b[y])
                {
                    if(c[x] < c[y])
                        swap(c[x], c[y]);
                }
                else if(b[x] == b[y] && c[x] == c[y])
                {
                    if(a[x] < a[y])
                        swap(a[x], a[y]);
                }
            }
        }
        for(int k = 0; k < m; k++)
        {
            if(a[k] >= b[k])
            {
                if(a[k] >= c[k])
                {
                    if(A * 2 < m)
                    {
                        ans += a[k];
                        A++;
                    }
                    else if(C * 2 < m)
                    {
                        ans += c[k];
                        C++;
                    }
                    else
                    {
                        ans += b[i];
                        B++;
                    }
                }
                else if(C * 2 < m)
                {
                    ans += c[k];
                    C++;
                }
                else
                {
                    ans += b[k];
                    B++;
                }
            }
            else if(b[k] >= c[k])
            {
                if(B * 2 < m)
                {
                    ans += b[k];
                    B++;
                }
                else if(C * 2 < m)
                {
                    ans += c[k];
                    C++;
                }
                else
                {
                    ans += a[k];
                    A++;
                }
            }
        }

        if(m == 2)
        {
            cout << max(a[0] + b[1], max(a[0] + c[1], max(b[0] + a[1], max(b[0] + c[1], max(c[0] + a[1], c[0] + b[1]))))) << '\n';
            continue;
        }
        cout << ans << '\n';
    }
    return 0;
}
