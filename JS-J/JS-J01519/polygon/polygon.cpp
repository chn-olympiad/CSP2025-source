#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 5, mod = 998244353;
int n, mx;
ll sum, ans;
int a[N];
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    // every equals to 1
    if(mx == 1)
    {
        ans = 1 << n;
        ans -= 1;
        ans -= n;
        ans -= n * (n - 1) / 2;
        cout << ans;
        return 0;
    }
    for(int i = 0; i < 1 << n; i++)
    {
        mx = sum = 0;
        for(int j = 1; j <= n; j++)
        {
            if(i >> (j - 1) & 1) sum += a[j], mx = max(mx, a[j]);
        }
        if(sum > mx * 2) ans = (ans + 1) % mod;
    }
    cout << ans;
	return 0;
}
