#include <bits/stdc++.h>
using namespace std;
int a[500005], pos = 0, tx[500005];
struct xr
{
    int l, r;
}b[5000005];
bool cmp(xr a, xr b)
{
    if(a.r != b.r)
        return a.r < b.r;
    return a.l < b.l;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int flag = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] != 1)
            flag  = 0;
    }
    if(flag)
    { 
        if(k == 0)
        {
            cout << n / 2;
        }
        else
        {
            cout << n;
        }
        cout << '\n';
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            tx[i] = (tx[i - 1] ^ a[i]);
        }
        for(int len = 1; len <= n; len++)
        {
            for(int l = 1; l  + len - 1 <= n; l++)
            {
                int r = l + len - 1;
                if((tx[r] ^ tx[l - 1]) == k)
                {
                    b[++pos] = {l, r};
                }
            }
        }
        sort(b + 1, b + pos + 1, cmp);
        int r = 0, cnt = 0;
        for(int i = 1; i <= pos; i++)
        {
            if(b[i].l <= r)
                continue;
            cnt++;
            r = b[i].r;
        }
        cout << cnt;
    }
    return 0;
}
// get test 1 - 12
// expected 50 pts