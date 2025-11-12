#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[250051][4];
ll ans = 0, n;
bool cmp(int x, int y)
{
	
}
void dfs(int cur, int cnt1, int cnt2, int cnt3, ll sum)
{
	if(cur == n + 1)
	{
		ans = max(ans, sum);
		return;
	}
	if(cnt1 < n / 2)
	{
		sum += a[cur][1];
		dfs(cur + 1, cnt1 + 1, cnt2, cnt3, sum);
		sum -= a[cur][1];
	}
	if(cnt2 < n / 2)
	{
		sum += a[cur][2];
		dfs(cur + 1, cnt1, cnt2 + 1, cnt3, sum);
		sum -= a[cur][2];
	}
	if(cnt3 < n / 2)
	{
		sum += a[cur][3];
		dfs(cur + 1, cnt1, cnt2, cnt3 + 1, sum);
		sum -= a[cur][3];
	}
}
ll aa[200051], bb[200051];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for(int x = 1; x <= t; x++)
	{
		scanf("%d", &n);
		bool A = 1;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			aa[i] = a[i][1];
			bb[i] = a[i][2];
			if(a[i][3] != 0) A = 0;
			if(a[i][2] != 0) A = 0;
		}
		if(A)
		{
			sort(aa + 1, aa + n + 1, cmp);
			for(int i = 1; i <= n / 2; i++)
			{
				ans += aa[i];
			}
			cout << ans << endl;
			ans = 0;
			continue;
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
