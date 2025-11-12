#include <iostream>
#include <algorithm>
using namespace std;

int a[100010][5];
int dp[100010];
int ans = -1;

void dfs1(int N, int k, int sum, int cnt1, int cnt2)
{
	if (cnt1 >= (N / 2) || cnt2 >= (N / 2)) return;
	if (k > N)
	{
		ans = max(ans, sum);
		return;
	}
	dfs1(N, k + 1, sum + a[k][1], cnt1 + 1, cnt2);
	dfs1(N, k + 1, sum + a[k][2], cnt1, cnt2 + 1);
}

void dfs2(int N, int k, int sum, int cnt1, int cnt2, int cnt3)
{
	if (cnt1 > (N / 2) || cnt2 > (N / 2) || cnt3 > (N / 2))
	{
		return;
	}
	if (k > N)
	{
		ans = max(ans, sum);
		return;
	}
	dfs2(N, k + 1, sum + a[k][1], cnt1 + 1, cnt2, cnt3);
	dfs2(N, k + 1, sum + a[k][2], cnt1, cnt2 + 1, cnt3);
	dfs2(N, k + 1, sum + a[k][3], cnt1, cnt2, cnt3 + 1);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 1; i <= 100000; i++)
			for (int j = 1; j <= 3; j++)
				a[i][j] = 0;
		
		int b1[20010], b2[20010], b3[20010];
		
		int n;
		cin >> n;
		ans = -1;
		int max_num = n / 2;
		bool f1 = true, f2 = true, f3 = true;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] != 0) f1 = false;
			if (a[i][2] != 0) f2 = false;
			if (a[i][3] != 0) f3 = false;
			b1[a[i][1]]++;
			b2[a[i][2]]++;
			b3[a[i][3]]++;
		}
		if (f3)
		{
			dfs1(n, 1, 0, 0, 0);
			cout << ans << endl;
			continue;
		}
		dfs2(n, 1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
