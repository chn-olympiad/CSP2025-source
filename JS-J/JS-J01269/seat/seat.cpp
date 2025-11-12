#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(ll a, ll b)
{
    return a > b;
}

ll n, m, a[1005], tar;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(ll i = 1; i <= n * m; i ++)
    {
        cin >> a[i];
    }
    tar = a[1];
    ll pos;
    sort(a + 1, a + n * m + 1, cmp);
    for(ll i = 1; i <= n * m; i ++)
    {
        if(a[i] == tar)
        {
            pos = i;
            break;
        }
    }
    if(pos % n == 0)
    {
        if((pos / n) % 2 == 0)
        {
            cout << pos / n << ' ' << 1;
        }
        else
        {
            cout << pos / n << ' ' << n;
        }
    }
    else
    {
        if((pos / n) % 2 == 0)
        {
            cout << pos / n + 1 << ' ' << pos % n;
        }
        else
        {
            cout << pos / n + 1 << ' ' << n - pos % n + 1;
        }
    }

    return 0;
}
