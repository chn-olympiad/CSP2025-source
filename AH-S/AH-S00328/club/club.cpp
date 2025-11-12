#include <chrono>
#include <random>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace std::chrono;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

constexpr size_t buf_size = 32 * 1024;
char in_buf[buf_size], out_buf[buf_size];

ll t, n;

namespace solution1
{
	constexpr ll N = 210;
	ll a[N], b[N], c[N], dp[N][N][N], ans;
	inline void work()
	{
			for(ll i = 1; i <= n; ++i)
				cin >> a[i] >> b[i] >> c[i];
			memset(dp, 0, sizeof(dp));
			dp[1][1][0] = a[1];
			dp[1][0][1] = b[1];
			dp[1][0][0] = c[1];
			for(ll i = 2; i <= n; ++i)
				for(ll j = 0; j <= min(i, n / 2); ++j)
					for(ll k = 0; k <= min(i, n / 2); ++k)
					{
						if(i - j - k < 0 || i - j - k > n / 2) 
							continue;
						if(j > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i]);
						if(k > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + b[i]);
						if(i - j - k > 0)
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]     + c[i]);
					}
			ans = 0;
			for(int j = 0; j <= n / 2; ++j)
				for(int k = 0; k <= n / 2; ++k)
					if(n - j - k <= n / 2)
						ans = max(ans, dp[n][j][k]);
			cout << ans << "\n";
	}	
}
namespace solution2
{
	constexpr ll N = 200005;
	ll ans;
	struct dat
	{
		ll a, b, c;
		friend bool operator < (const dat& lft, const dat& rgt)
		{
			return max({lft.a, lft.b, lft.c}) > max({rgt.a, rgt.b, rgt.c});
		}
	}arr[N];
	inline void work()
	{
		for(ll i = 1; i <= n; ++i)
			cin >> arr[i].a >> arr[i].b >> arr[i].c;
		sort(arr + 1, arr + 1 + n);
		ll ca = 0, cb = 0;
		ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			if(arr[i].a > arr[i].b)
			{
				if(ca < n / 2)
				{
					ans += arr[i].a;
					++ca;
				}
				else
				{
					ans += arr[i].b;
					++cb;
				}
			}
			else
			{
				if(cb < n / 2)
				{
					ans += arr[i].b;
					++cb;
				}
				else
				{
					ans += arr[i].a;
					++ca;
				}
			}
		}
		cout << ans << "\n";
	}
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin.rdbuf()->pubsetbuf(in_buf, buf_size);
	cout.rdbuf()->pubsetbuf(out_buf, buf_size);
	
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n < 205)
			solution1::work();
		else
			solution2::work();
	}
}

