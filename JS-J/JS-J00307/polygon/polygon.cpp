#include <bits/stdc++.h>

using namespace std;

int n;
int a[5010];
long long cnt;

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(n <= 3)
    {
        int x = a[1] + a[2] + a[3];
        if(x > 2 * a[1] && x > 2 * a[2] && x > 2 * a[3])
            cout << "1";
        else
            cout << "0";
        return 0;
    }
    bool pp = true;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != a[1])
        {
            pp = false;
            break;
        }
    }
    if(pp == true)
    {
        for(int i = 3; i <= n; i++)
        {
            int io = 1;
            for(int j = 0; j < i; j++)
            {
                io *= (n - j);
            }
            for(int j = 2; j <= i; j++)
                io /= j;
            cnt += io;
            cnt %= 944244353;
        }
        cout << cnt;
    }
    return 0;
}