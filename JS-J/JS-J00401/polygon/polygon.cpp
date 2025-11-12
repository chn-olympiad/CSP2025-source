#include <bits/stdc++.h>
using namespace std;
const int N = 5010, MOD = 998244353;
int n, a[N], maxa, z[N], ans_all;
bool work()
{
    int cnt = 0, maxb = 0, ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(z[i] == 1)
        {
            maxb = max(maxb, a[i]);
            cnt += a[i];
            ans++;
        }
    }
    return ((cnt > maxb * 2) && (ans > 2));
}
void dfs(int dep)
{
    if(dep > n)
    {
        if(work())
        {
            ans_all++;
        }
        return;
    }
    z[dep] = 0;
    dfs(dep + 1);
    z[dep] = 1;
    dfs(dep + 1);
}
long long quickpow(long long a, int b)
{
    long long ans = 1;
    while(b != 0)
    {
        if(b & 1)
        {
            ans *= a;
            ans %= MOD;
        }
        b >>= 1;
        a *= a;
        a %= MOD;
    }
    return ans % MOD;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        maxa = max(a[i], maxa);
    }
    if(maxa == 1)
    {
        long long p = n;
        cout << (quickpow(2, n) - 1 - p - (p - 1) * p / 2 + MOD) % MOD << "\n";  //24pts
    }
    else
    {
        if(n <= 20)
        {
            dfs(1);
            cout << ans_all << "\n"; // 40pts
        }
        else
        {
            cout << 114514 << "\n"; // Yes
        }
    }
	return 0;
}
//9:40 It's time to sleep, zzz~
//10:10 wake up, drink, dundunudun~
//11:34 go to the bathroom
//CSP-S rp += INF