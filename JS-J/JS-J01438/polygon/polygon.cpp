#include <bits/stdc++.h>
using namespace std;
long long s[5005], fac[5005];
const int m = 998244353;
long long qp(long long a, long long b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans % m * a % m) % m;
        a = (a % m * a % m) % m;
        b /= 2;
    }
    return ans;
}
long long C(int n, int i)
{
    return ((fac[n] % m * qp(fac[i], m - 2) % m) % m * qp(fac[n - i], m - 2) % m) % m;
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    long long n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    if(n <= 20)
    {
        for(long long i = 0; i < (1 << n); i++)
        {
            long long t = i, cnt = 0, mx = 0, pos = 0;
            while(t)
            {
                pos++;
                if(t % 2)
                {
                    cnt += s[pos];
                    mx = max(mx, s[pos]);
                }
                t /= 2;
            }
            if(cnt > 2 * mx)
            {
                ans = (ans + 1) % m;
            }
        }
    }
    else
    {
        fac[0] = 1;
        for(int i = 1; i <= 5000; i++)
        {
            fac[i] = (i % m * fac[i - 1] % m) % m;
        }
        for(int len = 3; len <= n; len++)
        {
            ans = (ans + C(n, len) % m) % m;
        }
    }
    cout << ans;
    return 0;
}
// get test 1 - 10, 15 - 20
// expected 60 pts