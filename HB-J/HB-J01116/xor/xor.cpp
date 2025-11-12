#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int n, k, a[500005];
bool vis[500005];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(n == 2 && a[1] == a[2])
    {
        cout << 1 << '\n';
        return 0;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            for(int j = 1; i + j <= n; j++)
            {
                int x = a[i];
                for(int k = i; k <= i + j; k++)
                {
                    x = x xor a[i];
                }
                if(x == k)
                {
                    for(int k = i; k <= i + j; k++)
                    {
                        vis[k] = 1;
                    }
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
