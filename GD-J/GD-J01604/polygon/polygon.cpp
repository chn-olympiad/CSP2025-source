#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

const int MOD = 998244353;
int n, a[5005];

int mx(int state)
{
    int ans = 0, i = 0;
    while (state)
    {
        i++;
        if (state & 1) ans = max(ans, a[i]);
        state >>= 1;
    }
    return ans;
}

int s(int state)
{
    int ans = 0, i = 0;
    while (state)
    {
    	i++;
    	if (state & 1) ans += a[i];
    	state >>= 1;
	}
	return ans;
}

int count(int state)
{
    int ans = 0, i = 0;
    while (state)
    {
    	i++;
    	if (state & 1) ans++;
    	state >>= 1;
	}
	return ans;
}

int powmod(int n)
{
	int ans = 1;
	for (int i = 1; i <= n; i++) ans = ans * 2 % MOD;
	return ans;
}

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n > 20)
    {
        cout << (powmod(n) - 1 - n - (n * (n - 1) >> 1)) % MOD;
        return 0;
    }
    for (int i = 7; i <= (1 << n) - 1; i++)
    {
        if (count(i) >= 3 && s(i) > 2 * mx(i)) ans++;
    }
    cout << ans;
	return 0;
}

