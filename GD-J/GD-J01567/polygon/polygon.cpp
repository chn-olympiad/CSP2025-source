#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e3 + 5;
const int M = 998244353;

int a[N], ans, n;

void dfs(int id, int sum, int cnt, int maxn)
{
	if(id > n)
	{
		if(cnt > 2 && sum > maxn * 2)
			++ans;
		return;
	}
	dfs(id + 1, sum + a[id], cnt + 1, max(maxn, a[id]));
	dfs(id + 1, sum, cnt, maxn);
}

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int maxa = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxa = max(maxa, a[i]);
	}
	
	if(maxa == 1)
	{
		ans = 1;
		for(int i = 1; i <= n; i++)
		{
			ans *= 2;
			ans %= M;
		}
		int cn0 = 1;
		int cn1 = n;
		int cn2 = n * (n - 1) / 2;
		ans = (ans + M - cn0 - cn1 - cn2) % M;
	}
	
	else if(n <= 20)
	{
		ans = 0;
		dfs(1, 0, 0, 0);
	}
	
//	else
//	{
//		ans = 0;
//		sort(a + 1, a + n + 1);
//		for(int m = n; m >= 3; m--)
//		{
//			for(int i = 1; i < m - 1; i++)
//			{
//				int sum = a[m] + a[i] + a[i + 1];
//				int j = i + 1;
//				while(sum <= 2 * a[m] && j < m)
//				{
//					j++;
//					sum += a[j];
//				}
//				ans += 
//			}
//		}
//	}

	cout << ans;
	
	return 0;
}

