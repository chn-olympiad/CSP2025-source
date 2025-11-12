#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005, MOD = 998244353;
int a[MAXN];
int n;

int max(int a, int b, int c)
{
	return max(a, max(b, c));
}

int solve(const int i, int &len, int &max_l, int &m)
{
	int ans = 0;
	for (int j = i + 1; j <= n; j++)
	{
		//cout << j << " " << len << " " << max_l << " " << m << endl;
		if (m >= 3 && len + a[j] > 2 * max(max_l, a[j]))
		{
			int temp_m = m, temp_len = len, temp_max_l = max_l;
			m++;
			ans++;
			ans %= MOD;
			len += a[j];
			max_l = max(max_l, a[j]);
			ans += solve(j, len, max_l, m);
			m = temp_m, len = temp_len, max_l = temp_max_l;
		}
		else if (m < 3)
		{
			int temp_m = m, temp_len = len, temp_max_l = max_l;
			m++;
			len += a[j];
			max_l = max(max_l, a[j]);
			ans += solve(j, len, max_l, m);
			m = temp_m, len = temp_len, max_l = temp_max_l; 
		}
	}
	return ans;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	int temp_a, temp_b, temp_c, temp_d = temp_c = temp_b = temp_a = 0;
	int ans = solve(temp_a, temp_b, temp_c, temp_d);
	
	cout << ans << "\n";
	
	return 0;
}
